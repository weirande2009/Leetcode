#include <vector>
using namespace std;

struct SegTree{
    int val;
    int begin;
    int end;
    SegTree* left;
    SegTree* right;
    SegTree(): val(0), begin(-1), end(-1), left(nullptr), right(nullptr){}
    SegTree(int val, int begin, int end): val(val), begin(begin), end(end), left(nullptr), right(nullptr){}
};

class NumArray {
private:
    vector<int> nums;
    SegTree* root;

    SegTree* buildSegTree(vector<int>& nums, int begin, int end){
        if(begin == end){
            return new SegTree(nums[begin], begin, end);
        }
        SegTree* node = new SegTree(0, begin, end);
        node->left = buildSegTree(nums, begin, (begin+end)/2);
        node->right = buildSegTree(nums, (begin+end)/2+1, end);
        node->val = node->left->val+node->right->val;
        return node;
    }

    void updateSegTree(SegTree* node, int index, int val){
        if(!node){
            return;
        }
        if(node->begin <= index && node->end >= index){
            node->val += val-nums[index];
            updateSegTree(node->left, index, val);
            updateSegTree(node->right, index, val);
        }
    }

    int sumSegTree(SegTree* node, int left, int right){
        if(!node){
            return 0;
        }
        if(left == node->begin && right == node->end){
            return node->val;
        }
        else if(node->left->end >= right){  // only in left
            return sumSegTree(node->left, left, right);
        }
        else if(node->right->begin <= left){  // only in right
            return sumSegTree(node->right, left, right);
        }
        else{  // in both
            return sumSegTree(node->left, left, node->left->end) + sumSegTree(node->right, node->right->begin, right);
        }
    }

public:
    NumArray(vector<int>& nums) {
        // segment tree
        this->nums = nums;
        root = buildSegTree(nums, 0, nums.size()-1);
    }
    
    void update(int index, int val) {
        updateSegTree(root, index, val);
        nums[index] = val;
    }
    
    int sumRange(int left, int right) {
        return sumSegTree(root, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */