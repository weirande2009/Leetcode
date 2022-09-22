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
    TreeNode* Recursion(const vector<int>& inorder, const vector<int>& postorder, int postorder_begin, int postorder_end, int inorder_begin, int inorder_end){
        if(postorder_begin > postorder_end || inorder_begin > inorder_end){
            return nullptr;
        }
        TreeNode* new_tree = new TreeNode(postorder[postorder_end]);
        if(postorder_begin == postorder_end){
            return new_tree;
        }
        // Find left part in inorder
        int inorder_first_index = index_record[postorder[postorder_end]];
        // Left
        new_tree->left = Recursion(inorder, postorder, postorder_begin, postorder_begin+(inorder_first_index-inorder_begin)-1, inorder_begin, inorder_first_index-1);
        
        // Right
        new_tree->right = Recursion(inorder, postorder, postorder_begin+(inorder_first_index-inorder_begin), postorder_end-1, inorder_first_index+1, inorder_end);
        
        return new_tree;
    }
    
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        for(int i=0; i<n; i++){
            index_record[inorder[i]] = i;
        }
        return Recursion(inorder, postorder, 0, n-1, 0, n-1);
    }
};