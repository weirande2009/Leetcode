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
    void dfs(TreeNode* root, int key){
        if(!root){
            return;
        }
        if(root->left){
            if(root->left->val == key){
                if(root->left->right){
                    // put root->left->left to root->left->right->...->left
                    if(root->left->left){
                        TreeNode* node = root->left->right;
                        while(node->left){
                            node = node->left;
                        }
                        node->left = root->left->left;
                    }
                    // put root->left->right to root->left
                    root->left = root->left->right;
                }
                else{
                    root->left = root->left->left;
                }
            }
            else{
                dfs(root->left, key);
            }
        }
        if(root->right){
            if(root->right->val == key){
                if(root->right->right){
                    // put root->right->left to root->right->right->...->left
                    if(root->right->left){
                        TreeNode* node = root->right->right;
                        while(node->left){
                            node = node->left;
                        }
                        node->left = root->right->left;
                    }
                    // put root->left->right to root->left
                    root->right = root->right->right;
                }
                else{
                    root->right = root->right->left;
                }
            }
            else{
                dfs(root->right, key);
            }
        }
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root){
            return nullptr;
        }
        if(root->val == key){
            if(root->right){
                TreeNode* node = root->right;
                while(node->left){
                    node = node->left;
                }
                node->left = root->left;
                return root->right;
            }
            else{
                return root->left;
            }
        }
        dfs(root, key);
        return root;
    }
};