
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
    bool sameTree(TreeNode* node1, TreeNode* node2){
        if(!node1 && !node2){
            return true;
        }
        else if(node1 && node2){
            return node1->val == node2->val && sameTree(node1->left, node2->left) && sameTree(node1->right, node2->right);
        }
        else{
            return false;
        }
    }

    void dfs(TreeNode* node, TreeNode* subRoot, bool& found){
        if(found){
            return;
        }
        if(!node){
            return;
        }
        if(sameTree(node, subRoot)){
            found = true;
        }
        else{
            dfs(node->left, subRoot, found);
            if(found){
                return;
            }
            dfs(node->right, subRoot, found);
            if(found){
                return;
            }
        }
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        bool found = false;
        dfs(root, subRoot, found);
        return found;
    }
};