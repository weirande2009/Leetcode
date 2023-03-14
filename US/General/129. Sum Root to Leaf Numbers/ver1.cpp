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
    void dfs(TreeNode* node, string& s, int& ans){
        s.push_back(node->val+'0');
        if(!node->left && !node->right){
            ans += stoi(s);
            s.pop_back();
            return;
        }
        
        if(node->left){
            dfs(node->left, s, ans);
        }
        if(node->right){
            dfs(node->right, s, ans);
        }
        s.pop_back();
    }

    int sumNumbers(TreeNode* root) {
        int ans = 0;
        string s;
        dfs(root, s, ans);
        return ans;
    }
};