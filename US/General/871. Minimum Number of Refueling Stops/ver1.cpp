#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        // dp[i] means the furthest we can go with i stops
        vector<int> dp(n+1, 0);
        dp[0] = startFuel;
        for(int i=0; i<n; i++){  // we stop at i
            for(int j=i; j>=0; j--){
                // if we can reach station i in j stops
                if(dp[j] >= stations[i][0]){
                    dp[j+1] = max((long long)dp[j+1], (long long)dp[j]+stations[i][1]);
                }
            }
        }
        for(int i=0; i<=n; i++){
            if(dp[i] >= target){
                return i;
            }
        }
        
        return -1;
    }
};