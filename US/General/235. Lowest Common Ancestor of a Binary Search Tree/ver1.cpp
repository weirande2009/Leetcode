#include <stdlib.h>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    TreeNode* dfs(TreeNode* root, int low, int high){
        if(!root){
            return nullptr;
        }
        if(root->val >= low && root->val <= high){
            return root;
        }
        else if(root->val < low){
            return dfs(root->right, low, high);
        }
        else{
            return dfs(root->left, low, high);
        }
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int low, high;
        if(p->val > q->val){
            low = q->val;
            high = p->val;
        }
        else{
            low = p->val;
            high = q->val;
        }
        return dfs(root, low, high);
    }
};