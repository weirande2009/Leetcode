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
    TreeNode* dfs(vector<int>& postorder, unordered_map<int, int>& inorder_hashtable, int pbegin, int pend, int ibegin, int iend){
        if(pbegin > pend || ibegin > iend){
            return nullptr;
        }
        // end is the node value
        TreeNode* node = new TreeNode(postorder[pend]);
        // find the end value in inorder, 
        int pos = inorder_hashtable[postorder[pend]];
        int left_l = pos - ibegin;
        int right_l = iend - pos;
        node->left = dfs(postorder, inorder_hashtable, pbegin, pbegin+left_l-1, ibegin, pos-1);
        node->right = dfs(postorder, inorder_hashtable, pbegin+left_l, pend-1, pos+1, iend);
        return node;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inorder_hashtable;
        int n = inorder.size();
        for(int i=0; i<n; i++){
            inorder_hashtable[inorder[i]] = i;
        }
        return dfs(postorder, inorder_hashtable, 0, n-1, 0, n-1);
    }
};