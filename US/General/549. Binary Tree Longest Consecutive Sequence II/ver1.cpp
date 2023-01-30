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
    // pair consists of 1 and -1 consecutive array length
    pair<int, int> dfs(TreeNode* node, int parent, int& ans){
        if(!node){
            return {0, 0};
        }
        pair<int, int> left = dfs(node->left, node->val, ans);
        pair<int, int> right = dfs(node->right, node->val, ans);
        ans = max(ans, max(left.first+right.second, left.second+right.first)+1);
        pair<int, int> ret;
        if(node->val - parent == 1){
            ret.first = 1 + max(left.first, right.first);
        }
        else{
            ret.first = 0;
        }
        if(node->val - parent == -1){
            ret.second = 1 + max(left.second, right.second);
        }
        else{
            ret.second = 0;
        }
        return ret;
    }

    int longestConsecutive(TreeNode* root) {
        int ans = 0;
        dfs(root, 100000, ans);
        return ans;
    }
};