#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    vector<int> pre;
    vector<int> post;

public:
    void preTraverse(TreeNode* root, int layer){
        if(root->left){
            preTraverse(root->left, layer+1);
        }
        else{
            if(root->right){
                pre.push_back(-123356*layer);
            }
        }
        pre.push_back(root->val);
        if(root->right){
            preTraverse(root->right, layer+1);
        }
        else{
            if(root->left){
                pre.push_back(-123357*layer);
            }
        }
    }

    void postTraverse(TreeNode* root, int layer){
        if(root->right){
            postTraverse(root->right, layer+1);
        }
        else{
            if(root->left){
                post.push_back(-123356*layer);
            }
        }
        post.push_back(root->val);
        if(root->left){
            postTraverse(root->left, layer+1);
        }
        else{
            if(root->right){
                post.push_back(-123357*layer);
            }
        }
    }

    bool isSymmetric(TreeNode* root) {
        if(!root){
            return true;
        }
        preTraverse(root, 1);
        postTraverse(root, 1);
        for(int i=0; i<pre.size(); i++){
            if(pre[i] != post[i]){
                return false;
            }
        }
        return true;
    }
};

int main(){
    TreeNode* root = new TreeNode(5);
    TreeNode* left = new TreeNode(4);
    TreeNode* right = new TreeNode(1);
    TreeNode* left_right = new TreeNode(1);
    TreeNode* right_right = new TreeNode(4);
    TreeNode* left_right_left = new TreeNode(2);
    TreeNode* right_right_left = new TreeNode(2);
    root->left = left;
    root->right = right;
    left->right = left_right;
    right->right = right_right;
    left_right->left = left_right_left;
    right_right->left = right_right_left;
    Solution s;
    s.isSymmetric(root);
}
