#include <algorithm>
#include <limits.h>
using namespace std;

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
    void dfs(TreeNode* root, int layer, int& m){
        if(!root || layer >= m){
            return;
        }
        if(!root->left && !root->right){
            m = min(layer, m);
            return;
        }
        dfs(root->left, layer+1, m);
        dfs(root->right, layer+1, m);
    }
    
    int minDepth(TreeNode* root) {
        if(!root){
            return 0;
        }
        int m = INT_MAX;
        dfs(root, 0, m);
        return m+1;
    }
};