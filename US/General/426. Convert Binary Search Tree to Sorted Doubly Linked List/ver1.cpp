#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
public:
    void dfs(Node* node, vector<Node*>& v){
        if(!node){
            return;
        }
        dfs(node->left, v);
        v.push_back(node);
        dfs(node->right, v);
    }

    Node* treeToDoublyList(Node* root) {
        if(!root){
            return root;
        }
        vector<Node*> v;
        dfs(root, v);
        int n = v.size();
        for(int i=0; i<n; i++){
            v[i]->left = v[(i-1+n)%n];
            v[i]->right = v[(i+1)%n];
        }
        return v[0];
    }
};