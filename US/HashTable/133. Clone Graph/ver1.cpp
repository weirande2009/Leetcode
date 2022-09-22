#include <vector>
#include <unordered_map>
using namespace std;

// Algorithm: Use recursion to solve this problem. In every recursion, given origin node and 
// a new node which has added to map, which means that the new node has been constructed, but
// it's neighbors are not added yet. Then, traverse neighbors of origin node, and search the 
// node value in map. If exist, which means this node has been constructed, then just add the
// value in map to neighbor. If not exist, which means this node hasn't been constructed yet,
// then new a neighbor node and add this new node and correspond origin node to a vector.
// And add this new node to map. After traversing, we are going to traverse the new neighbor
// node vector. For each new neighbot node, use recursion.

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
private:
    unordered_map<int, Node*> record;
    
    
public:
    void Recursion(Node* node, Node* new_node){
        vector<Node*> new_nodes;
        vector<Node*> old_nodes;
        for(int i=0; i<node->neighbors.size(); i++){
            auto f = record.find(node->neighbors[i]->val);
            if(f == record.end()){
                Node* new_neighbor = new Node(node->neighbors[i]->val);
                new_node->neighbors.push_back(new_neighbor);
                record[node->neighbors[i]->val] = new_neighbor;
                new_nodes.push_back(new_neighbor);
                old_nodes.push_back(node->neighbors[i]);
            }
            else{
                new_node->neighbors.push_back(f->second);
            }
        }
        for(int i=0; i<new_nodes.size(); i++){
            Recursion(old_nodes[i], new_nodes[i]);
        }
    }
    
    Node* cloneGraph(Node* node) {
        if(node == nullptr){
            return nullptr;
        }
        Node* new_node = new Node(node->val);
        record[node->val] = new_node;
        Recursion(node, new_node);
        return new_node;
    }
};




