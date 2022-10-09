#include <vector>
using namespace std;

// Algorithm: O(n). First record each Treenode into a vector in preorder traversal.
// Then find to treenode val in vector that are not in the correct position and swap them.


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
    void swap(int& a, int& b){
        int tmp = a;
        a = b;
        b = tmp;
    }
    
    void recursion(TreeNode* root, vector<TreeNode*>& nodes){
        if(!root){
            return;
        }
        recursion(root->left, nodes);
        nodes.push_back(root);
        recursion(root->right, nodes);
    }
    
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> nodes;
        recursion(root, nodes);
        int first = -1;
        int second = -1;
        for(int i=1; i<nodes.size(); i++){
            if(nodes[i]->val < nodes[i-1]->val){
                if(first == -1){
                    first = i-1;
                    second = i;
                }
                else{
                    second = i;
                    break;
                }
            }
        }
        swap(nodes[first]->val, nodes[second]->val);
    }
};