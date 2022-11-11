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
    void dfs(TreeNode* root, int val, bool& found){
        if(!root || found){
            return;
        }
        dfs(root->left, val, found);
        if(found){
            return;
        }
        if(root->val >= val){
            TreeNode* node = new TreeNode(val);
            node->left = root->left;
            root->left = node;
            found = true;
        }
        dfs(root->right, val, found);
    }
    
    TreeNode* find(TreeNode *root){
        if(!root->right){
            return root;
        }
        return find(root->right);
    }
    
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root){
            return new TreeNode(val);
        }
        bool found = false;
        dfs(root, val, found);
        if(!found){
            TreeNode* last = find(root);
            last->right = new TreeNode(val);
        }
        return root;
    }
};