#include <vector>
#include <limits.h>
using namespace std;


class Solution {
public:
    // find the minimum number of subarrays needed to reach the max sum of max_sum
    int find(vector<int>& nums, int max_sum, int n){
        int sum = 0;
        int subarray_count = 1;
        for(int i=0; i<n; i++){
            // add until larger than max)sum
            if(nums[i] > max_sum){
                return INT_MAX;
            }
            if(sum + nums[i] <= max_sum){
                sum += nums[i];
            }
            else{
                sum = nums[i];
                subarray_count++;
            }
        }
        return subarray_count;
    }
    
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        // binary search all possible max sum
        int low = INT_MIN;  // low is the largest num in nums
        int high = 0;  // high is the sum of nums
        for(int i=0; i<n; i++){
            low = max(low, nums[i]);
            high += nums[i];
        }
        while(low < high){
            int mid = (low+high) / 2;
            if(find(nums, mid, n) <= k){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        if(find(nums, low-1, n) <= k){
            return low-1;
        }
        else if(find(nums, low, n) <= k){
            return low;
        }
        else{
            return low+1;
        }
    }
};