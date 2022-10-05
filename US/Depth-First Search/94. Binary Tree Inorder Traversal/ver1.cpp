#include <vector>
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
    void recursion(TreeNode* root, vector<int>& result){
        if(root->left){
            recursion(root->left, result);
        }
        result.push_back(root->val);
        if(root->right){
            recursion(root->right, result);
        }
    }
    
    
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root){
            return {};
        }
        vector<int> result;
        recursion(root, result);
        return result;
    }
};