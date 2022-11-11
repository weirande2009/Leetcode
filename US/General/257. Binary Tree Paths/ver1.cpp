#include <vector>
#include <string>
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
    void dfs(TreeNode* root, vector<int>& route, vector<string>& result){
        if(!root){
            return;
        }
        route.push_back(root->val);
        if(!root->left && !root->right){
            string s = to_string(route[0]);
            for(int i=1; i<route.size(); i++){
                s += "->";
                s += to_string(route[i]);
            }
            result.push_back(s);
        }
        else{
            dfs(root->left, route, result);
            dfs(root->right, route, result);
        }
        route.erase(route.begin()+route.size()-1);
    }
    
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int> route;
        vector<string> result;
        dfs(root, route, result);
        return result;
    }
};