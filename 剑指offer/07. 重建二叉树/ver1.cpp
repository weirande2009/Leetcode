#include <vector>
#include <unordered_map>
using namespace std;

// 解题思路
// 利用递归，通过对于先序遍历和中序遍历结果的性质以及生成方式，来反向地解题。

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    unordered_map<int, int> index;

public:
    TreeNode* recursionBuildTree(const vector<int>& preorder, const vector<int>& inorder, int preorder_left, int preorder_right, int inorder_left, int inorder_right){
        if(preorder_left > preorder_right){
            return nullptr;
        }

        // The first in preorder is root
        int preorder_root = preorder_left;
        // Get index of root in inorder
        int inorder_root = index[preorder[preorder_root]];

        // Build pre node
        TreeNode* node = new TreeNode(preorder[preorder_root]);

        // Traverse left node
        int left_node_num = inorder_root - inorder_left;  // Compute the length of left node
        node->left = recursionBuildTree(preorder, inorder, preorder_root+1, preorder_root+left_node_num, inorder_left, inorder_root-1);

        // Traverse right node
        node->right = recursionBuildTree(preorder, inorder, preorder_root+left_node_num+1, preorder_right, inorder_root+1, inorder_right);

        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        // Generate hash map of index and node value
        for(int i=0; i<n; i++){
            index[inorder[i]] = i;
        }
        return recursionBuildTree(preorder, inorder, 0, n-1, 0, n-1);
    }
};