#include <vector>
using namespace std;

class NumArray {
public:
    vector<int> cumsum;

    NumArray(vector<int>& nums) {
        cumsum.push_back(0);
        cumsum.push_back(nums[0]);
        int n = nums.size();
        for(int i=1; i<n; i++){
            cumsum.push_back(nums[i]+cumsum[i]);
        }
    }
    
    int sumRange(int left, int right) {
        return cumsum[right+1]-cumsum[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */