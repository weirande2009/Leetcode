
// Algorithm: For each recursion, compute the height of left and right and compare to their
// height. Add return the higher height of left and right + 1 as the height of current node.


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
    int Recursion(TreeNode* root, bool& flag){
        if(!flag){
            return 0;
        }
        if(!root){
            return 0;
        }
        int left_layer = Recursion(root->left, flag);
        int right_layer = Recursion(root->right, flag);
        if(left_layer == right_layer){
            return left_layer+1;
        }
        else if(left_layer+1 == right_layer){
            return right_layer+1;
        }
        else if(left_layer == right_layer+1){
            return left_layer+1;
        }
        else{
            flag = false;
            return 0;
        }
    }
    
    
    bool isBalanced(TreeNode* root) {
        bool flag = true;
        Recursion(root, flag);
        return flag;
    }
};