#include <unordered_map>
#include <string>
using namespace std;

class MyTreeNode{
public:
    char val;
    bool last;
    unordered_map<char, MyTreeNode*> children;
    
    MyTreeNode(char c){
        val = c;
        last = false;
    }
    
    void addChild(char c){
        if(children.find(c) == children.end()){
            MyTreeNode* node = new MyTreeNode(c);
            children[c] = node;
        }
    }
    
    MyTreeNode* getChild(char c){
        if(children.find(c) != children.end()){
            return children[c];
        }
        else{
            return nullptr;
        }
    }
    
    bool hasChild(char c){
        if(children.find(c) != children.end()){
            return true;
        }
        else{
            return false;
        }
    }
    
    void setLast(){
        last = true;
    }
    
};

class Trie {
private:
    MyTreeNode* root;
    
public:
    Trie() {
        root = new MyTreeNode('\0');
    }
    
    void insert(string word) {
        MyTreeNode* node = root;
        for(char c: word){
            // add child
            node->addChild(c);
            // get the next
            node = node->getChild(c);
        }
        node->setLast();
    }
    
    bool search(string word) {
        MyTreeNode* node = root;
        for(char c: word){
            // find c
            if(!node->hasChild(c)){
                return false;
            }
            // get the next
            node = node->getChild(c);
        }
        if(node->last){
            return true;
        }
        else{
            return false;
        }
    }
    
    bool startsWith(string prefix) {
        MyTreeNode* node = root;
        for(char c: prefix){
            // find c
            if(!node->hasChild(c)){
                return false;
            }
            // get the next
            node = node->getChild(c);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */