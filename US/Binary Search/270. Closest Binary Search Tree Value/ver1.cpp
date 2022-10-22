#include <cmath>
#include <limits.h>

// Algorithm: Use dfs to search the binary tree and compute the distance of each node.

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
    void dfs(TreeNode* root, double target, int& cur_node, double& min_dis){
        if(abs(root->val - target) < min_dis){
            min_dis = abs(root->val - target);
            cur_node = root->val;
        }
        if(target > root->val){
            if(root->right){
                dfs(root->right, target, cur_node, min_dis);
            }
        }
        else if(target < root->val){
            if(root->left){
                dfs(root->left, target, cur_node, min_dis);
            }
        }
    }
    
    
    int closestValue(TreeNode* root, double target) {
        int cur_node;
        double min_dis = INT_MAX;
        dfs(root, target, cur_node, min_dis);
        return cur_node;
    }
};