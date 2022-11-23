#include <unordered_set>
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
    void dfs(TreeNode* root, TreeNode* parent, unordered_set<TreeNode*>& hashtable, int& ans){
        if(!root){
            return;
        }
        // from bottom to top, dfs
        dfs(root->left, root, hashtable, ans);
        dfs(root->right, root, hashtable, ans);
        
        // greedy, set camera when we can set
        // for the root node, in case the root node is not monitored
        if(!parent && hashtable.find(root) == hashtable.end()){
            ans++;
            // add the current node, children and parent
            hashtable.insert(root);
            hashtable.insert(root->left);
            hashtable.insert(root->right);
            hashtable.insert(parent);
        }
        // for every other node, if children not monitored, set camera and add all other monitored node, which is greedy
        if(hashtable.find(root->left) == hashtable.end() || hashtable.find(root->right) == hashtable.end()){
            // a new camera
            ans++;
            // add the current node, children and parent
            hashtable.insert(root);
            hashtable.insert(root->left);
            hashtable.insert(root->right);
            hashtable.insert(parent);
        }
    }
    
    int minCameraCover(TreeNode* root) {
        unordered_set<TreeNode*> hashtable;
        hashtable.insert(nullptr);
        int ans = 0;
        dfs(root, nullptr, hashtable, ans);
        return ans;
    }
};