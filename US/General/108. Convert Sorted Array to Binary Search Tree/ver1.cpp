#include <vector>
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
    TreeNode* dfs(vector<int>& nums, int begin, int end){
        if(begin > end){
            return nullptr;
        }
        TreeNode* node = new TreeNode(nums[(begin+end)/2]);
        node->left = dfs(nums, begin, (begin+end)/2-1);
        node->right = dfs(nums, (begin+end)/2+1, end);
        return node;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        return dfs(nums, 0, n-1);
    }
};