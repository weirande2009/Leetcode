
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
    void Recursion(TreeNode* root, int& max_layer, int cur_layer){
        if(!root){
            return;
        }
        Recursion(root->left, max_layer, cur_layer+1);
        if(cur_layer > max_layer){
            max_layer = cur_layer;
        }
        Recursion(root->right, max_layer, cur_layer+1);
    }
    
    
    int maxDepth(TreeNode* root) {
        int max_layer = 0;
        Recursion(root, max_layer, 1);
        return max_layer;
    }
};