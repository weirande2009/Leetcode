




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
    TreeNode* dfs(TreeNode* root){
        TreeNode* left_last = nullptr;
        if(root->left){
            left_last = dfs(root->left);
        }
        if(left_last){
            left_last->right = root->right;
            root->right = root->left;
            root->left = nullptr;
        }
        TreeNode* most_right;
        if(left_last){
            most_right = left_last;
            if(left_last->right){
                most_right = dfs(left_last->right);
            }
        }
        else{
            most_right = root;
            if(root->right){
                most_right = dfs(root->right);
            }
        }
        return most_right;
    }
    
    void flatten(TreeNode* root) {
        if(!root){
            return;
        }
        dfs(root);
    }
};