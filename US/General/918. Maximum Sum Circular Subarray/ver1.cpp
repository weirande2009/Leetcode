#include <vector>
#include <limits.h>
using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int max_so_far = INT_MIN;
        int max_ending_here = 0;
        for(int i=0; i<n; i++){
            max_ending_here += nums[i];
            max_so_far = max(max_so_far, max_ending_here);
            max_ending_here = max(max_ending_here, 0);
        }
        vector<int> prefix_sum(n, 0);
        prefix_sum[0] = nums[0];
        for(int i=1; i<n; i++){
            prefix_sum[i] += prefix_sum[i-1] + nums[i];
        }
        vector<int> suffix_sum(n, 0);
        int max_suffix_sum = INT_MIN;
        int suffix_sum_here = 0;
        for(int i=n-1; i>=0; i--){
            suffix_sum_here += nums[i];
            max_suffix_sum = max(max_suffix_sum, suffix_sum_here);
            suffix_sum[i] = max_suffix_sum;
        }
        for(int i=0; i<n-1; i++){
            max_so_far = max(max_so_far, prefix_sum[i]+suffix_sum[i+1]);
        }
        return max_so_far;
    }
};