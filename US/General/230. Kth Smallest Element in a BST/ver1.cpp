
// Algorithm: preorder

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
    void dfs(TreeNode* root, int k, int& count, bool& found, int& result){
        if(!root || found){
            return;
        }
        dfs(root->left, k, count, found, result);
        count++;
        if(count == k){
            result = root->val;
            found = true;
        }
        dfs(root->right, k, count, found, result);
        return;
    }
    
    
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        bool found = false;
        int result;
        dfs(root, k, count, found, result);
        return result;
    }
};