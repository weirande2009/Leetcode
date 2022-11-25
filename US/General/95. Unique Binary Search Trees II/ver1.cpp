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
    vector<TreeNode*> dfs(int start, int end){
        if(start > end){
            return {nullptr};
        }
        vector<TreeNode*> nodes;
        for(int i=start; i<=end; i++){
            // get all possible left 
            vector<TreeNode*> left = dfs(start, i-1);
            // get all possible right
            vector<TreeNode*> right = dfs(i+1, end);
            // get all combinations and create current node and add the tree to nodes
            for(int j=0; j<left.size(); j++){
                for(int k=0; k<right.size(); k++){
                    TreeNode* tmp = new TreeNode(i);
                    tmp->left = left[j];
                    tmp->right = right[k];
                    nodes.push_back(tmp);
                }
            }
        }
        return nodes;
    }
    
    
    vector<TreeNode*> generateTrees(int n) {
        return dfs(1, n);
    }
};