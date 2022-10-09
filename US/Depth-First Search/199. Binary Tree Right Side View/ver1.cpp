#include <vector>
#include <queue>
using namespace std;

// Algorithm: Use BFS to search the tree. First push root node to a queue. Then, add the first
// node's val to a vector. And then, iterate the queue, first add node's right node to a new
// queue, then left one. Substitute the old queue with the new queue. Just like search the tree
// layer by layer and find the rightest node's val.

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

    vector<int> rightSideView(TreeNode* root) {
        if(!root){
            return {};
        }
        queue<TreeNode*> q;
        vector<int> results;
        q.push(root);
        while(!q.empty()){
            queue<TreeNode*> new_q;
            results.push_back(q.front()->val);
            while(!q.empty()){
                if(q.front()->right){
                    new_q.push(q.front()->right);
                }
                if(q.front()->left){
                    new_q.push(q.front()->left);
                }
                q.pop();
            }
            
            q = new_q;
        }
        return results;
    }
};