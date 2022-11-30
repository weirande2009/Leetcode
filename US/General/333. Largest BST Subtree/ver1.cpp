#include <vector>
#include <limits.h>
using namespace std;

// top-down dp dfs

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct Ret{
    int mx;
    int mn;
    bool bst;
    int num;
    Ret() : mx(INT_MIN), mn(INT_MAX), bst(true), num(0) {}
};

class Solution {
public:
    Ret dfs(TreeNode* root){
        if(!root->left && !root->right){
            Ret ret;
            ret.mx = root->val;
            ret.mn = root->val;
            ret.bst = true;
            ret.num = 1;
            return ret;
        }
        bool bst = true;
        Ret left;
        if(root->left){
            left = dfs(root->left);
        }
        Ret right;
        if(root->right){
            right = dfs(root->right);
        }
        // Check whether this is a bst
        Ret ret;
        if(left.bst && right.bst && left.mx < root->val && right.mn > root->val){
            if(!root->left){
                ret.mn = root->val;
            }
            else{
                ret.mn = left.mn;
            }
            if(!root->right){
                ret.mx = root->val;
            }
            else{
                ret.mx = right.mx;
            }
            ret.bst = true;
            ret.num = left.num + right.num + 1;
        }
        else{
            ret.num = max(left.num, right.num);
            ret.bst = false;
        }
        return ret;
    }
    
    int largestBSTSubtree(TreeNode* root) {
        if(!root){
            return 0;
        }
        return max(dfs(root).num, 1);
    }
};