#include <bits/stdc++.h>
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
    void dfs(TreeNode* node, vector<int>& v){
        if(!node){
            return;
        }
        v.push_back(node->val);
        dfs(node->left, v);
        dfs(node->right, v);
    }

    int minDiffInBST(TreeNode* root) {
        vector<int> v;
        dfs(root, v);
        int ans = INT_MAX;
        for(int i=0; i<v.size(); i++){
            for(int j=i+1; j<v.size(); j++){
                ans = min(ans, abs(v[i]-v[j]));
            }
        }
        return ans;
    }
};