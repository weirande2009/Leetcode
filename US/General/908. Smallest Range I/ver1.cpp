#include <vector>
#include <limits.h>
using namespace std;


class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int n = nums.size();
        int mn = INT_MAX;
        int mx = INT_MIN;
        for(int i=0; i<n; i++){
            mn = min(nums[i], mn);
            mx = max(nums[i], mx);
        }
        mn += k;
        mx -= k;
        return mn > mx? 0 : mx - mn;
    }
};