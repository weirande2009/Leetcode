//Algorithm: dfs, for each recursion, first find there are p or q in left and right, and get two
// boolean, has_left and has_right. They are true, if there are p or q in left or right.
// Then Judge root->val is p or q, and get a boolean, has. has = true, if root->val is p or q.
// Then when two of has_left, has_right, has are true, we find the answer and record it.
// return has || has_left || has_right.

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool dfs(TreeNode* root, int p, int q, TreeNode*& result, bool& found){
        if(!root || found){
            return false;
        }
        bool has = false;
        bool left_has = dfs(root->left, p, q, result, found);
        bool right_has = dfs(root->right, p, q, result, found);
        if(root->val == p || root->val == q){
            has = true;
        }
        if((left_has && right_has && !has && !found) || (!left_has && right_has && has && !found) || (left_has && !right_has && has && !found)){
            result = root;
            found = true;
        }
        return has || left_has || right_has;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* result;
        bool found = false;
        dfs(root, p->val, q->val, result, found);
        return result;
    }
};