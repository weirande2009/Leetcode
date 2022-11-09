#include <vector>
#include <unordered_set>
using namespace std;

// Algorithm: inorder traversal so that all duplicated number will continuously being traversed.
// First, compute the max number. Then traverse again to find all the modes.

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
    void dfs(TreeNode* root, int& m, int& c, int& n){
        if(!root){
            return;
        }
        dfs(root->left, m, c, n);
        if(root->val == c){
            n++;
        }
        else{
            c = root->val;
            n = 1;
        }
        m = max(m, n);
        dfs(root->right, m, c, n);
    }
    
    void dfs1(TreeNode* root, int m, int& c, int& n, unordered_set<int>& modes){
        if(!root){
            return;
        }
        dfs1(root->left, m, c, n, modes);
        if(root->val == c){
            n++;
        }
        else{
            c = root->val;
            n = 1;
        }
        if(n == m){
            modes.insert(root->val);
        }
        dfs1(root->right, m, c, n, modes);
    }
    
    vector<int> findMode(TreeNode* root) {
        if(!root){
            return {};
        }
        int m = 0;
        int n = 0;
        int c = root->val;
        dfs(root, m, c, n);
        unordered_set<int> modes;
        n = 0;
        c = root->val;
        dfs1(root, m, c, n, modes);
        return vector<int>(modes.begin(), modes.end());
    }
};