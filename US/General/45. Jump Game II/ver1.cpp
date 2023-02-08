#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        // dp[i] means the minimum number of jumps from 0 to i
        vector<int> dp(n, INT_MAX);
        dp[0] = 0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<=i+nums[i] && j<n; j++){
                dp[j] = min(dp[j], dp[i]+1);
            }
        }
        return dp[n-1];
    }
};