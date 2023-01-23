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
    int dfs(TreeNode* node, vector<vector<int>>& ans){
        if(!node){
            return 0;
        }
        int layer = max(dfs(node->left, ans), dfs(node->right, ans));
        // this is the first time comes to the layer
        if(ans.size() <= layer){
            ans.push_back({node->val});
        }
        else{
            ans[layer].push_back(node->val);
        }
        return layer+1;
    }

    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> ans;
        dfs(root, ans);
        return ans;
    }
};