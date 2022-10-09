#include <unistd.h>


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
    bool Recursion(TreeNode* p, TreeNode* q){
        if(p == NULL && q == NULL){
            return true;
        }
        else if(p == NULL || q == NULL){
            return false;
        }
        if(p->val == q->val){
            return Recursion(p->left, q->right) && Recursion(p->right, q->left);
        }
        else{
            return false;
        }
    }
    
    bool isSymmetric(TreeNode* root) {
        return Recursion(root->left, root->right);
    }
};