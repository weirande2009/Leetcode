#include <vector>
#include <limits.h>
using namespace std;


class Solution {
public:
    int dfs(vector<vector<int>>& costs, vector<vector<int>>& dp, int city1, int city2, int n){
        // if no more people can go to city 1 or city 2, return INT_MIN
        if(city1 > n || city2 > n){
            return 1000000;
        }
        int i = city1 + city2;
        if(i == 2*n){
            return 0;
        }
        // if cached
        if(dp[i][city1] != -1){
            return dp[i][city1];
        }
        int to_city1 = costs[i][0] + dfs(costs, dp, city1+1, city2, n);
        int to_city2 = costs[i][1] + dfs(costs, dp, city1, city2+1, n);
        int ans = min(to_city1, to_city2);
        dp[i][city1] = ans;
        return ans;
    }
    
    
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size();
        // dp[i][j] means that the min cost when people from i to n has been scheduled
        // and there are j people go to city 1.
        vector<vector<int>> dp(n, vector<int>(n/2+1, -1));
        int ans = dfs(costs, dp, 0, 0, n/2);
        return ans;
    }
};