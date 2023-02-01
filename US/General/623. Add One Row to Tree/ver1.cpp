#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void add(TreeNode* node, int val, int depth, int layer){
        if(!node){
            return;
        }
        if(layer == depth-1){
            TreeNode* left = new TreeNode(val);
            TreeNode* right = new TreeNode(val);
            left->left = node->left;
            right->right = node->right;
            node->left = left;
            node->right = right;
            return;
        }
        add(node->left, val, depth, layer+1);
        add(node->right, val, depth, layer+1);
    }

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode* new_root = new TreeNode(val);
            new_root->left = root;
            return new_root;
        }
        add(root, val, depth, 1);
        return root;
    }
};