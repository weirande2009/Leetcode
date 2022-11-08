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
    vector<int> dfs(TreeNode* root){
        if(!root){
            return {0, 0};
        }
        vector<int> left = dfs(root->left);
        vector<int> right = dfs(root->right);
        // if we rob this node, we cannot rob its children
        int rob = root->val + left[1] + right[1];
        // if we don't rob this node, we can rob its children or not
        int notrob = max(left[0], left[1]) + max(right[0], right[1]);
        return {rob, notrob};
    }
    
    int rob(TreeNode* root) {
        vector<int> result = dfs(root);
        return max(result[0], result[1]);
    }
};