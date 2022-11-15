#include <vector>
using namespace std;

// Algorithm: dp[i] means the min cost to climb to i and 
// dp[i] = min(dp[i-2]+cost[i-2], dp[i-1]+cost[i-1]);

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if(n == 1){
            return cost[0];
        }
        // dp[i] means the min cost to climb to i
        vector<int> dp(n+1, 0);
        dp[0] = 0;
        dp[1] = 0;
        for(int i=2; i<n+1; i++){
            dp[i] = min(dp[i-2]+cost[i-2], dp[i-1]+cost[i-1]);
        }
        return dp[n];
    }
};