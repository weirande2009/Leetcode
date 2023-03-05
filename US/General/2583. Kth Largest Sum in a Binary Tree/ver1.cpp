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
    void dfs(TreeNode* node, vector<long long>& sum, int layer){
        if(!node){
            return;
        }
        if(sum.size() < layer+1){
            sum.push_back(0);
        }
        sum[layer] += node->val;
        dfs(node->left, sum, layer+1);
        dfs(node->right, sum, layer+1);
    }
    
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> sum;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            queue<TreeNode*> tmp_q;
            long long s = 0;
            while(!q.empty()){
                TreeNode* node = q.front();
                s += node->val;
                if(node->left){
                    tmp_q.push(node->left);
                }
                if(node->right){
                    tmp_q.push(node->right);
                }
                q.pop();
            }
            sum.push_back(s);
            q = tmp_q;
        }
        sort(sum.begin(), sum.end(), greater<long long>());
        return sum.size() < k ? -1 : sum[k-1];
    }
};