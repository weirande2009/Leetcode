#include <vector>
#include <limits.h>
using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int max_so_far = INT_MIN;
        int min_so_far = INT_MAX;
        int min_ending_here = 0;
        int max_ending_here = 0;
        int sum = 0;
        // consider the subarray with circle is that we get rid of a subarray inside the array, and the left is 
        // a subarray with circle. So we can also try to find the minimum subarray inside the nums.
        for(int i=0; i<n; i++){
            min_ending_here += nums[i];
            max_ending_here += nums[i];
            max_so_far = max(max_so_far, max_ending_here);
            min_so_far = min(min_so_far, min_ending_here);
            max_ending_here = max(max_ending_here, 0);
            min_ending_here = min(min_ending_here, 0);
            sum += nums[i];
        }
        // if sum == min_so_far, now we get rid of all the nums which is invalid, and in this situation,
        // all the numbers in array is negative so this problem can be seen as a normal one.
        return sum == min_so_far ? max_so_far : max(max_so_far, sum-min_so_far);
    }
};