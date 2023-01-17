#include <vector>
#include <cmath>
using namespace std;

class NumArray {
private:
    vector<int> nums;
    vector<int> cumsum;
    int s;

public:
    NumArray(vector<int>& nums) {
        // split nums into sqrt(n) sums
        this->nums = nums;
        int n = nums.size();
        double l = sqrt(n);
        s = ceil(l);
        int i=0;
        while(i < n){
            int sum = 0;
            for(int j=0; i<n && j<s; j++, i++){
                sum += nums[i];
            }
            cumsum.push_back(sum);
        }
    }
    
    void update(int index, int val) {
        int i = index / s;
        cumsum[i] += val-nums[index];
        nums[index] = val;
    }
    
    int sumRange(int left, int right) {
        int sum = 0;
        int begin = left/s;
        int end = right/s;
        for(int i=begin; i<=end; i++){
            sum += cumsum[i];
        }
        for(int i=begin*s; i<left; i++){
            sum -= nums[i];
        }
        for(int i=right+1; i<(end+1)*s && i<nums.size(); i++){
            sum -= nums[i];
        }
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */