
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    void inorderSearch(TreeNode* root, TreeNode* p, bool& found, TreeNode*& ans){
        if(!root){
            return;
        }
        if(found && ans){
            return;
        }
        inorderSearch(root->left, p, found, ans);
        if(found && !ans){
            ans = root;
            return;
        }
        if(p == root){
            found = true;
        }
        inorderSearch(root->right, p, found, ans);
    }

    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        bool found = false;
        TreeNode* ans = nullptr;
        inorderSearch(root, p, found, ans);
        return ans;
    }
};