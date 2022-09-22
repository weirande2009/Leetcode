#include <vector>
using namespace std;

// Algorithm: the preorder consist of three part in order: node value, left part, right part
// the inorder consist of three part in order: left part, node value, right part.
// And "part" mentioned above can also be a preorder and an inorder.
// So we use recursion to solve this problem.

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
    TreeNode* Recursion(const vector<int>& preorder, const vector<int>& inorder, int preorder_begin, int preorder_end, int inorder_begin, int inorder_end){
        if(preorder_begin > preorder_end || inorder_begin > inorder_end){
            return nullptr;
        }
        TreeNode* new_tree = new TreeNode(preorder[preorder_begin]);
        if(preorder_begin == preorder_end){
            return new_tree;
        }
        // Find left part in inorder
        int inorder_first_index = 0;
        for(int i=inorder_begin; i<=inorder_end; i++){
            if(inorder[i] == preorder[preorder_begin]){
                inorder_first_index = i;
                break;
            }
        }
        // Left
        new_tree->left = Recursion(preorder, inorder, preorder_begin+1, preorder_begin+(inorder_first_index-inorder_begin), inorder_begin, inorder_first_index-1);
        
        // Right
        new_tree->right = Recursion(preorder, inorder, preorder_begin+(inorder_first_index-inorder_begin)+1, preorder_end, inorder_first_index+1, inorder_end);
        
        return new_tree;
    }
    
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        return Recursion(preorder, inorder, 0, n-1, 0, n-1);
    }
};


int main(){
    vector<int> preorder = {1, 2};
    vector<int> inorder = {2, 1};
    Solution s;
    s.buildTree(preorder, inorder);




}


