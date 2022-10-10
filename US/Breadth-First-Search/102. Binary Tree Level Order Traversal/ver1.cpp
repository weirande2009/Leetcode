#include <vector>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root){
            return {};
        }
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> result;
        while(!q.empty()){
            vector<int> tmp;
            queue<TreeNode*> new_q;
            while(!q.empty()){
                tmp.push_back(q.front()->val);
                if(q.front()->left)
                    new_q.push(q.front()->left);
                if(q.front()->right)
                    new_q.push(q.front()->right);
                q.pop();
            }
            q = new_q;
            result.push_back(tmp);
        }
        return result;
    }
};