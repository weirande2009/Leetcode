#include <unordered_map>
using namespace std;


struct Node{
    int val;
    int key;
    Node* prev;
    Node* next;
    Node(int v, int k) : val(v), key(k), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    Node* head;
    Node* tail;
    int size;
    unordered_map<int, Node*> cache;
    int capacity;
    
public:
    LRUCache(int capacity) {
        this->head = new Node(-1, -1);
        this->tail = new Node(-1, -1);
        this->head->next = this->tail;
        this->tail->prev = this->head;
        this->capacity = capacity;
        this->size = 0;
    }
    
    void move(Node* node){
        remove(node, false);
        insert(node);
    }
    
    void remove(Node* node, bool deleted=true){
        node->prev->next = node->next;
        node->next->prev = node->prev;
        if(deleted){
            delete node;
        }
    }
    
    void insert(Node* node){
        node->prev = head;
        node->next = head->next;
        
        head->next->prev = node;
        head->next = node;
    }
    
    int get(int key) {
        if(cache.find(key) == cache.end()){
            return -1;
        }
        else{
            move(cache[key]);
            return cache[key]->val;
        }
    }
    
    void put(int key, int value) {
        if(cache.find(key) == cache.end()){
            if(size == capacity){
                // remove
                cache.erase(tail->prev->key);
                remove(tail->prev);
                size--;
            }
            // insert new
            Node* node = new Node(value, key);
            cache[key] = node;
            insert(node);
            size++;
        }
        else{
            move(cache[key]);
            cache[key]->val = value;
        }
    }
        
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */