#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     Node *left;
 *     Node *right;
 *     Node *random;
 *     Node() : val(0), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x) : val(x), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x, Node *left, Node *right, Node *random) : val(x), left(left), right(right), random(random) {}
 * };
 */

class Solution {
public:
    NodeCopy* dfs(Node* node, unordered_map<Node*, NodeCopy*>& node_to_nodecopy, unordered_map<NodeCopy*, Node*>& nodecopy_to_node){
        if(!node){
            return nullptr;
        }
        NodeCopy* node_copy = new NodeCopy(node->val);
        node_copy->left = dfs(node->left, node_to_nodecopy, nodecopy_to_node);
        node_copy->right = dfs(node->right, node_to_nodecopy, nodecopy_to_node);
        node_to_nodecopy[node] = node_copy;
        nodecopy_to_node[node_copy] = node->random;
        return node_copy;
    }

    void dfs2(NodeCopy* node, unordered_map<Node*, NodeCopy*>& node_to_nodecopy, unordered_map<NodeCopy*, Node*>& nodecopy_to_node){
        if(!node){
            return;
        }
        node->random = node_to_nodecopy[nodecopy_to_node[node]];
        dfs2(node->left, node_to_nodecopy, nodecopy_to_node);
        dfs2(node->right, node_to_nodecopy, nodecopy_to_node);
    }

    NodeCopy* copyRandomBinaryTree(Node* root) {
        unordered_map<Node*, NodeCopy*> node_to_nodecopy;
        unordered_map<NodeCopy*, Node*> nodecopy_to_node;
        NodeCopy* root_copy = dfs(root, node_to_nodecopy, nodecopy_to_node);
        dfs2(root_copy, node_to_nodecopy, nodecopy_to_node);
        return root_copy;
    }
};