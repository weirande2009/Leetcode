#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int twoSumLessThanK(vector<int>& nums, int k) {
        // nums[i]+nums[j] is the same as nums[j]+nums[i]
        sort(nums.begin(), nums.end());
        int ans = -1;
        int n = nums.size();
        for(int i=0; i<n; i++){
            int upper = k-nums[i];
            auto it = lower_bound(nums.begin()+i+1, nums.end(), upper);
            if(it > nums.begin()+i+1){
                ans = max(ans, nums[i]+*(--it));
            }
        }
        return ans;
    }
};