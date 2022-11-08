#include <algorithm>
using namespace std;
// Algorithm: Compute the deepest depth of each node and return the depth.

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
    int dfs(TreeNode* root, int& length){
        if(!root){
            return 0;
        }
        int left = dfs(root->left, length);
        int right = dfs(root->right, length);
        // Judge diameter
        length = max(length, left+right);
        return max(left, right)+1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int length = 0;
        dfs(root, length);
        return length;
    }
};