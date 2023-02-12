#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        long long count = 0;
        for(int i=0; i<n; i++){
            int l = lower - nums[i];
            int u = upper - nums[i];
            // search from i+1, because if there are valid answer before, they have been counted
            auto lower_it = lower_bound(nums.begin()+i+1, nums.end(), l);
            auto upper_it = upper_bound(nums.begin()+i+1, nums.end(), u);
            count += upper_it-lower_it;
        }
        return count;
    }
};
