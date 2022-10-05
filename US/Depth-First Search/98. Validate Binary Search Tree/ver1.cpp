#include <climits>

// Algorithm: Depth-first search. for each search time, we set a lower and upper bound for a 
// tree. So for current node, its left tree's value should in [lower, current_val-1] and 
// right tree's value should in [current_val+1, upper].

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
    void recursion(TreeNode* root, bool& flag, int lower, int upper){
        if(!flag){
            return;
        }
        if(root->left){
            if(!(lower <= root->left->val && root->left->val < root->val)){
                flag = false;
                return;
            }
            recursion(root->left, flag, lower, root->val-1);
        }
        if(root->right){
            if(!(root->val < root->right->val && root->right->val <= upper)){
                flag = false;
                return;
            }
            recursion(root->right, flag, root->val+1, upper);
        }   
    }
    
    bool isValidBST(TreeNode* root) {
        bool flag = true;
        if(root->left){
            if(root->val <= root->left->val){
                return false;
            }
            recursion(root->left, flag, -INT_MAX-1, root->val-1);
        }
        if(root->right){
            if(root->val >= root->right->val){
                return false;
            }
            recursion(root->right, flag, root->val+1, INT_MAX);
        } 
        return flag;
    }
};