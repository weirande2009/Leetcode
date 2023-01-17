#include <vector>
#include <map>
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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if(!root){
            return {};
        }
        map<int, vector<int>> hashtable;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while(!q.empty()){
            hashtable[q.front().second].push_back(q.front().first->val);
            if(q.front().first->left){
                q.push({q.front().first->left, q.front().second-1});
            }
            if(q.front().first->right){
                q.push({q.front().first->right, q.front().second+1});
            }
            q.pop();
        }
        vector<vector<int>> ans;
        for(auto& p: hashtable){
            ans.push_back(p.second);
        }
        return ans;
    }
};