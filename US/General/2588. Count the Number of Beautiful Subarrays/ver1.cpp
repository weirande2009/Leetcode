#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> dp;
        long long count = 0;
        int prefix = 0;
        dp[0] = 1;
        for(int i=0; i<n; i++){
            prefix ^= nums[i];
            count += dp[prefix]++;
        }
        return count;
    }
};