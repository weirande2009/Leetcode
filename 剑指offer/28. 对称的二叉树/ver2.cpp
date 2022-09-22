#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    bool symmetric = true;

public:
    void RecursionCompare(TreeNode* left, TreeNode* right){
        if(!left || !right){
            if(left){
                symmetric = false;
            }
            else if(right){
                symmetric = false;
            }
        }
        else{
            if(left->val == right->val){
                RecursionCompare(left->left, right->right);
                RecursionCompare(left->right, right->left);
            }
            else{
                symmetric = false;
            }
        }
        
    }

    bool isSymmetric(TreeNode* root) {
        if(!root){
            return true;
        }
        RecursionCompare(root, root);
        return symmetric;
    }
};

int main(){
    TreeNode* root = new TreeNode(5);
    TreeNode* left = new TreeNode(4);
    TreeNode* right = new TreeNode(1);
    TreeNode* left_right = new TreeNode(1);
    TreeNode* right_right = new TreeNode(4);
    TreeNode* left_right_left = new TreeNode(2);
    TreeNode* right_right_left = new TreeNode(2);
    root->left = left;
    root->right = right;
    left->right = left_right;
    right->right = right_right;
    left_right->left = left_right_left;
    right_right->left = right_right_left;
    Solution s;
    s.isSymmetric(root);
}
