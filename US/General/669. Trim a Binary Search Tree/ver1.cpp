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
    void cutMin(TreeNode* root, int low){
        if(!root){
            return;
        }
        if(root->left){
            if(root->left->val < low){
                if(root->left->right){
                    root->left = root->left->right;
                    cutMin(root, low);
                }
                else{
                    root->left = nullptr;
                }
            }
            else{
                cutMin(root->left, low);
            }
        }
    }
    
    void cutMax(TreeNode* root, int high){
        if(!root){
            return;
        }
        if(root->right){
            if(root->right->val > high){
                if(root->right->left){
                    root->right = root->right->left;
                    cutMax(root, high);
                }
                else{
                    root->right = nullptr;
                }
            }
            else{
                cutMax(root->right, high);
            }
        }
    }
    
    TreeNode* findFirst(TreeNode* root, int low, int high){
        if(!root){
            return nullptr;
        }
        if(root->val < low){
            return findFirst(root->right, low, high);
        }
        else if(root->val > high){
            return findFirst(root->left, low, high);
        }
        else{
            return root;
        }
    }
    
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(!root){
            return nullptr;
        }
        TreeNode* node = findFirst(root, low, high);
        cutMin(node, low);
        cutMax(node, high);
        return node;
    }
};