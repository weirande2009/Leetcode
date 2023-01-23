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
    void dfs(TreeNode* node, int targetSum, vector<vector<int>>& ans, vector<int>& route, int sum){
        if(!node){
            return;
        }
        route.push_back(node->val);
        if(!node->left && !node->right){
            if(node->val+sum == targetSum){
                ans.push_back(route);
            }
        }
        dfs(node->left, targetSum, ans, route, node->val+sum);
        dfs(node->right, targetSum, ans, route, node->val+sum);
        route.erase(route.begin()+route.size()-1);
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> route;
        dfs(root, targetSum, ans, route, 0);
        return ans;
    }
};