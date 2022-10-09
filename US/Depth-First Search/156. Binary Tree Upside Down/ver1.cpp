
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
    void Recursion(TreeNode* root, TreeNode** new_root){
        if(root->left->left){
            Recursion(root->left, new_root);
            TreeNode* tmp = root->left;
            tmp->left = root->right;
            root->left = nullptr;
            root->right = nullptr;
            tmp->right = root;
        }
        else{
            TreeNode* tmp = root->left;
            tmp->left = root->right;
            root->left = nullptr;
            root->right = nullptr;
            tmp->right = root;
            (*new_root) = tmp;
        }
    }
    
    
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if(!root){
            return nullptr;
        }
        if(!root->left){
            return root;
        }
        TreeNode* new_root;
        Recursion(root, &new_root);
        root->left = nullptr;
        root->right = nullptr;
        return new_root;
    }
};