
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    TreeNode* result;
    
public:
    void dfs(TreeNode* root, int val, bool& found){
        if(!root || found){
            return;
        }
        if(root->val == val){
            result = root;
            found = true;
        }
        else if(root->val > val){
            dfs(root->left, val, found);
        }
        else{
            dfs(root->right, val, found);
        }
    }
    
    TreeNode* searchBST(TreeNode* root, int val) {
        bool found = false;
        dfs(root, val, found);
        return result;
    }
};