#include <queue>
#include <cmath>
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
    int countNodes(TreeNode* root) {
        if(!root){
            return 0;
        }
        int count = 0;
        queue<TreeNode*> q;
        q.push(root);
        bool last_layer = false;
        int layer = 0;
        while(!q.empty()){
            layer++;
            count = 0;
            queue<TreeNode*> new_q;
            while(!q.empty()){
                TreeNode* node = q.front();
                q.pop();
                if(node->left){
                    count++;
                    new_q.push(node->left);
                }
                else{
                    last_layer = true;
                }
                if(node->right){
                    count++;
                    new_q.push(node->right);
                }
                else{
                    last_layer = true;
                }
                if(last_layer){
                    break;
                }
            }
            q = new_q;
            if(last_layer){
                return pow(2, layer)+count-1;   
            }
        }
        return 0;
    }
};