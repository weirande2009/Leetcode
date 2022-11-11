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
    void dfs(TreeNode* root, int sum, int target, bool& found){
        if(!root || found){
            return;
        }
        sum += root->val;
        if(!root->left && !root->right){
            if(sum == target){
                found = true;
            }
        }
        else{
            dfs(root->left, sum, target, found);
            dfs(root->right, sum, target, found);
        }
    }
    
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root){
            return false;
        }
        bool found = false;
        dfs(root, 0, targetSum, found);
        return found;
    }
};