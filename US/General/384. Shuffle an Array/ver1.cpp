#include <vector>
#include <cmath>
using namespace std;

class Solution {
private:
    vector<int> nums;
    vector<int> origin;

public:
    Solution(vector<int>& nums) {
        origin = nums;
        this->nums = nums;
    }
    
    vector<int> reset() {
        return origin;
    }
    
    vector<int> shuffle() {
        for(int pivot = nums.size()-1; pivot > 0; pivot--){
            int r = rand() % (pivot+1);
            if(r == 1){
                int tmp = nums[0];
                nums[0] = nums[pivot];
                nums[pivot] = tmp;
            }
        }
        return nums;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */