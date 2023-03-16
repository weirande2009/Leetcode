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
    TreeNode* dfs(vector<int>& preorder, int begin, int end){
        if(begin > end){
            return nullptr;
        }
        TreeNode* node = new TreeNode(preorder[begin]);
        int pos = end;  // record the first larger than preorder[begin]
        for(int i=begin+1; i<=end; i++){
            if(preorder[i] > preorder[begin]){
                pos = i-1;
                break;
            }
        }
        node->left = dfs(preorder, begin+1, pos);
        node->right = dfs(preorder, pos+1, end);
        return node;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        return dfs(preorder, 0, n-1);
    }
};