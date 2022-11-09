#include <algorithm>
#include <limits.h>
using namespace std;

// Algorithm: Use inorder to make to node consecutive;

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
    void dfs(TreeNode* root, int& c, int& m){
        if(!root){
            return;
        }
        dfs(root->left, c, m);
        m = min(m, abs(root->val-c));
        c = root->val;
        dfs(root->right, c, m);
    }
    
    int getMinimumDifference(TreeNode* root) {
        int c = INT_MAX;
        int m = INT_MAX;
        dfs(root, c, m);
        return m;
    }
};