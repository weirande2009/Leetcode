#include <deque>
#include <vector>
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root){
            return {};
        }
        deque<TreeNode*> q;
        q.push_back(root);
        vector<vector<int>> result;
        int direction = 1;
        while(!q.empty()){
            vector<int> tmp;
            deque<TreeNode*> new_q;
            while(!q.empty()){
                if(direction == 1){
                    tmp.push_back(q.front()->val);
                    if(q.front()->left)
                        new_q.push_front(q.front()->left);
                    if(q.front()->right)
                        new_q.push_front(q.front()->right);
                    q.pop_front();
                }
                else{
                    tmp.push_back(q.front()->val);
                    if(q.front()->right)
                        new_q.push_front(q.front()->right);
                    if(q.front()->left)
                        new_q.push_front(q.front()->left);
                    q.pop_front();
                }
            }
            direction *= -1;
            q = new_q;
            result.push_back(tmp);
        }
        return result;
    }
};

