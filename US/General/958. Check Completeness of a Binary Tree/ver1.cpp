#include <bits/stdc++.h>
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
    void depth_search(TreeNode* node, int layer, int& depth){
        if(!node){
            depth = max(depth, layer);
            return;
        }
        depth_search(node->left, layer+1, depth);
        depth_search(node->right, layer+1, depth);
    }

    void completeness_search(TreeNode* node, int layer, int depth, bool& encounter_incomplete, bool& complete){
        if(!complete){
            return;
        }
        if(layer != depth){
            if(!node){
                complete = false;
            }
            else{
                completeness_search(node->left, layer+1, depth, encounter_incomplete, complete);
                completeness_search(node->right, layer+1, depth, encounter_incomplete, complete);
            }
        }
        else{
            if(!node){
                encounter_incomplete = true;
            }
            else{
                if(encounter_incomplete){
                    complete = false;
                }
            }
        }
    }

    bool isCompleteTree(TreeNode* root) {
        int depth = 0;
        depth_search(root, 0, depth);
        bool encounter_incomplete = false;
        bool complete = true;
        completeness_search(root, 0, depth-1, encounter_incomplete, complete);
        return complete;
    }
};