#include <vector>
#include <limits.h>
using namespace std;

// Algorithm: For each iteration, we sum the current nums[i] until it's larger than target.
// If it's larger than target, we record the length and minus the left number and left++.
// If the sum less than target, we sum the next one.


class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        int left = 0;
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += nums[i];
            while(sum >= target){
                ans = min(ans, i+1-left);
                sum -= nums[left++];
            }
            
        }
        return ans==INT_MAX ? 0 : ans;
    }
};