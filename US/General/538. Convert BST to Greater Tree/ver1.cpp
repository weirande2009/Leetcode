#include <limits.h>
using namespace std;

// Travesal from the biggest number and record duplicate value and compute the sum

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
    void dfsadd(TreeNode* root, int& sum, int& c, int& n){
        if(!root){
            return;
        }
        dfsadd(root->right, sum, c, n);
        if(root->val == c){
            n++;
            root->val += sum;
        }
        else{
            sum += n*c;
            n = 1;
            c = root->val;
            root->val += sum;
        }
        dfsadd(root->left, sum, c, n);
    }
    
    
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        int c = INT_MAX;
        int n = 0;
        dfsadd(root, sum, c, n);
        return root;
    }
};