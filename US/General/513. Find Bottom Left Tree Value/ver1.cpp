#include <queue>
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
    int findBottomLeftValue(TreeNode* root) {
        if(!root){
            return 0;
        }
        int count = 0;
        queue<TreeNode*> q;
        q.push(root);
        int left = 0;
        while(!q.empty()){
            queue<TreeNode*> new_q;
            bool has_left = false;
            while(!q.empty()){
                TreeNode* node = q.front();
                q.pop();
                if(!has_left){
                    has_left = true;
                    left = node->val;
                }
                if(node->left){
                    new_q.push(node->left);
                }
                if(node->right){
                    new_q.push(node->right);
                }
            }
            q = new_q;
        }
        return left;
        
    }
};