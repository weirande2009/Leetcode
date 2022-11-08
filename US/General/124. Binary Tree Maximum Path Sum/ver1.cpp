#include <algorithm>
#include <limits.h>
using namespace std;

// Algorithm: for each node, compute the max sum of path till for the node. return the max 
// path sum

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
    int dfs(TreeNode* root, int& sum){
        if(!root){
            return 0;
        }
        int left = dfs(root->left, sum);
        int right = dfs(root->right, sum);
        int tmp = root->val;
        if(right > 0){
            tmp += right;
        }
        if(left > 0){
            tmp += left;
        }
        sum = max(tmp, sum);
        return max(max(left, right), 0)+root->val;
    }
    
    int maxPathSum(TreeNode* root) {
        int sum = -INT_MAX;
        dfs(root, sum);
        return sum;
        
    }
};