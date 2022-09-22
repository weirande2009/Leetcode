#include <vector>
#include <unordered_map>
using namespace std;

// Algorithm: in the basis of version1. Version1 use loop to find the node value in inorder.
// Because this tree contain unique value, we use a map to record value -> index. 
// So when we can find the node value in constant time.

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
private:
    unordered_map<int, int> index_record;
    
public:
    TreeNode* Recursion(const vector<int>& preorder, const vector<int>& inorder, int preorder_begin, int preorder_end, int inorder_begin, int inorder_end){
        if(preorder_begin > preorder_end || inorder_begin > inorder_end){
            return nullptr;
        }
        TreeNode* new_tree = new TreeNode(preorder[preorder_begin]);
        if(preorder_begin == preorder_end){
            return new_tree;
        }
        // Find left part in inorder
        int inorder_first_index = index_record[preorder[preorder_begin]];
        // Left
        new_tree->left = Recursion(preorder, inorder, preorder_begin+1, preorder_begin+(inorder_first_index-inorder_begin), inorder_begin, inorder_first_index-1);
        
        // Right
        new_tree->right = Recursion(preorder, inorder, preorder_begin+(inorder_first_index-inorder_begin)+1, preorder_end, inorder_first_index+1, inorder_end);
        
        return new_tree;
    }
    
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        for(int i=0; i<n; i++){
            index_record[inorder[i]] = i;
        }
        return Recursion(preorder, inorder, 0, n-1, 0, n-1);
    }
};