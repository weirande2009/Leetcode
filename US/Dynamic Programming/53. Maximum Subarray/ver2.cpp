#include <vector>
#include <limits.h>
using namespace std;

// Algorithm: O(n). First set max_num as the max number in nums. Then use a variable left_sum
// to record the current sum of sub array. Then, traverse the array which set i from 0 to n-1.
// If nums[i] > 0, add it to left_sum, because it will increase it and compare it to max_sum. 
// If nums[i] < 0, compare it to left_sum. If nums[i] + left_sum > 0, just add it to left_sum, 
// else set left_sum to 0, because this is the end of the sub array, or it will become negative.


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }
        int max_sum = -INT_MAX;
        for(int i=0; i<n; i++){
            if(nums[i] > max_sum){
                max_sum = nums[i];
            }
        }
        int left_sum = 0;
        // Find left
        for(int i=0; i<n; i++){
            if(nums[i] < 0){
                if(left_sum + nums[i] > 0){
                    left_sum += nums[i];
                }
                else{
                    left_sum = 0;
                }
            }
            else{
                left_sum += nums[i];
                if(left_sum > max_sum){
                    max_sum = left_sum;
                }
            }
        }
        return max_sum;
    }
};


