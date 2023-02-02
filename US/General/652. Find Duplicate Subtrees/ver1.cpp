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
    int construct(TreeNode* node, vector<pair<TreeNode*, int>>& vector_tree){
        if(!node){
            return 0;
        }
        int layer_left = construct(node->left, vector_tree);
        int layer_right = construct(node->right, vector_tree);
        vector_tree.push_back({node, max(layer_left, layer_right)+1});
        return max(layer_left, layer_right)+1;
    }

    bool sameTree(TreeNode* node1, TreeNode* node2){
        if(!node1 && !node2){
            return true;
        }
        else if(node1 && node2){
            if(node1->val == node2->val){
                return sameTree(node1->left, node2->left) && sameTree(node1->right, node2->right);
            }
            else{
                return false;
            }
        }
        else{
            return false;
        }
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<pair<TreeNode*, int>> vector_tree;
        vector<TreeNode*> ans;
        construct(root, vector_tree);
        vector<bool> visited(vector_tree.size(), false);
        for(int i=0; i<vector_tree.size(); i++){
            if(visited[i]){
                continue;
            }
            bool has = false;
            visited[i] = true;
            for(int j=i+1; j<vector_tree.size(); j++){
                if(vector_tree[i].second == vector_tree[j].second && vector_tree[i].first->val == vector_tree[i].first->val && sameTree(vector_tree[i].first, vector_tree[j].first)){
                    visited[j] = true;
                    has = true;
                }
            }
            if(has){
                ans.push_back(vector_tree[i].first);
            }
        }
        return ans;
    }
};