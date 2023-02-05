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
    vector<TreeNode*> allPossibleFBT(int n) {
        if(n % 2 == 0){
            return {};
        }
        vector<vector<TreeNode*>> dp(n+1);
        dp[1].push_back(new TreeNode(0));
        for(int i=3; i<=n; i+=2){
            for(int j=1; j<=i/2; j+=2){
                for(int k=0; k<dp[j].size(); k++){
                    for(int l=0; l<dp[i-j-1].size(); l++){
                        TreeNode* node = new TreeNode(0);
                        node->left = dp[j][k];
                        node->right = dp[i-j-1][l];
                        dp[i].push_back(node);
                        if(i-j-1 != j){
                            TreeNode* node1 = new TreeNode(0);
                            node1->left = dp[i-j-1][l];
                            node1->right = dp[j][k];
                            dp[i].push_back(node1);
                        }
                    }
                }
            }
        }
        return dp[n];
    }
};