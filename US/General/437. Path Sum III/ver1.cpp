#include <unordered_map>
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
    void dfs(TreeNode* root, unordered_map<long long, long long>& targets, int& number, int targetSum){
        if(!root){
            return;
        }
        unordered_map<long long, long long> new_targets;
        for(auto a: targets){
            long long i = a.first;
            if(root->val == i){
                number += a.second;
            }
            new_targets[i-root->val] = a.second;
        }
        if(root->val == targetSum){
            number++;
        }
        if(new_targets.find(targetSum-root->val) != targets.end()){
            new_targets[targetSum-root->val]++;
        }
        else{
            new_targets[targetSum-root->val] = 1;
        }
        dfs(root->left, new_targets, number, targetSum);
        dfs(root->right, new_targets, number, targetSum);
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, long long> targets;
        int number = 0;
        dfs(root, targets, number, targetSum);
        return number;
    }
};