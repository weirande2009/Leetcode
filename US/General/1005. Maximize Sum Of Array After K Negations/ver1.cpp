#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;


class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int sum = 0;
        int last_neg = -1;
        // flip all negative numbers
        for(int i=0; i<n; i++){
            if(nums[i] < 0 && k > 0){
                nums[i] *= -1;
                k--;
                last_neg = i;
            }
            sum += nums[i];
        }
        if(k % 2){
            int mn = INT_MAX;
            for(int num: nums){
                mn = min(mn, num);
            }
            sum -= 2*mn;
        }
        
        return sum;
    }
};