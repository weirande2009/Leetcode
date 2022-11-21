#include <vector>
#include <unordered_map>
#include <limits.h>
using namespace std;

/**
 * dp[i][j] means that all tasks before i have been scheduled and there are j free slots now.
 * 
*/
int dfs(vector<int>& costs, vector<int>& times, vector<int>& after_sum, vector<unordered_map<int, int>>& dp, int i, int j, int n){
    if(j+after_sum[i] < 0){
        return INT_MIN;
    }
    if(dp[i].find(j) != dp[i].end()){
        return dp[i][j];
    }
    if(i == n){
        return 0;
    }
    // schedule i to the paid server, then search for the next task i+1 and now there are j+times[i] free slots
    int paid = costs[i] + dfs(costs, times, after_sum, dp, i+1, j+times[i], n);
    // schedule i to the free server, then search for the next task i+1 and now there are j-1 free slots
    int fre = dfs(costs, times, after_sum, dp, i+1, j-1, n);
    int ans = min(paid, fre);
    dp[i][j] = ans;
    return ans;
}

int TasksScheduling(vector<int>& costs, vector<int>& times){
    int n = costs.size();
    // after_sum[i] means the sum of times[i:] which means the max number of possible free slots
    vector<int> after_sum(n+1);
    // dp[i][j] means that all tasks before i have been scheduled and there are j free slots now.
    // and j can be negative which means there are j slots needed to be filled by afterwards tasks
    vector<unordered_map<int, int>> dp(n);
    after_sum[n] = 0;
    for(int i=n-1; i>=0; i--){
        after_sum[i] = after_sum[i+1] + times[i];
    }
    int ans = dfs(costs, times, after_sum, dp, 0, 0, n);
    return ans;
}