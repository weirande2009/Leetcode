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
        int m = nums[begin];
        int p = begin;
        for(int i=begin+1; i<=end; i++){
            if(nums[i] > m){
                m = nums[i];
                p = i;
            }
        }
        TreeNode* node = new TreeNode(m);
        node->left = dfs(nums, begin, p-1);
        node->right = dfs(nums, p+1, end);
        return node;
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return dfs(nums, 0, nums.size()-1);
    }
};