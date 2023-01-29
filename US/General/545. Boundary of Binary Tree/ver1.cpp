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
    void dfs_left(TreeNode* node, vector<int>& left_boundary){
        if(!node->left && !node->right){
            return;
        }
        left_boundary.push_back(node->val);
        if(node->left){
            dfs_left(node->left, left_boundary);
        }
        else if(node->right){
            dfs_left(node->right, left_boundary);
        }
    }

    void dfs_right(TreeNode* node, vector<int>& right_boundary){
        if(!node->left && !node->right){
            return;
        }
        right_boundary.push_back(node->val);
        if(node->right){
            dfs_right(node->right, right_boundary);
        }
        else if(node->left){
            dfs_right(node->left, right_boundary);
        }
    }

    void dfs_leaves(TreeNode* node, vector<int>& leaves){
        if(!node->left && !node->right){
            leaves.push_back(node->val);
            return;
        }
        if(node->left){
            dfs_leaves(node->left, leaves);
        }
        if(node->right){
            dfs_leaves(node->right, leaves);
        }
    }

    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> left_boundary;
        vector<int> right_boundary;
        vector<int> leaves;
        if(root->left){
            dfs_left(root->left, left_boundary);
        }
        if(root->right){
            dfs_right(root->right, right_boundary);
        }
        if(root->left || root->right){
            dfs_leaves(root, leaves);
        }
        vector<int> ans = {root->val};
        ans.insert(ans.end(), left_boundary.begin(), left_boundary.end());
        ans.insert(ans.end(), leaves.begin(), leaves.end());
        ans.insert(ans.end(), right_boundary.rbegin(), right_boundary.rend());
        return ans;
    }
};