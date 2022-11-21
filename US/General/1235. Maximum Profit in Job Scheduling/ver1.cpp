#include <vector>
#include <algorithm>
using namespace std;

// Algorithm: O(nlogn)

class Solution {
public:
    int dfs(vector<int>& startTime, vector<int>& endTime, vector<int>& profit, int n, int i, vector<int>& memo){
        if(i == n){
            return 0;
        }
        if(memo[i] != -1){
            return memo[i];
        }
        // find the next non-conflicting job
        int next_index = lower_bound(startTime.begin(), startTime.end(), endTime[i])-startTime.begin();
        // the max of skipping and scheduling is the answer
        // skipping is to the next
        // scheduling is to the next non-conflicting index
        int ans = max(dfs(startTime, endTime, profit, n, i+1, memo), dfs(startTime, endTime, profit, n, next_index, memo)+profit[i]);
        memo[i] = ans;
        return ans;
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> total;
        int n = startTime.size();
        for(int i=0; i<n; i++){
            total.push_back({startTime[i], endTime[i], profit[i]});
        }
        sort(total.begin(), total.end(), [](const vector<int>& v1, const vector<int>& v2){
           return v1[0] < v2[0]; 
        });
        for(int i=0; i<n; i++){
            startTime[i] = total[i][0];
            endTime[i] = total[i][1];
            profit[i] = total[i][2];
        }
        // memo[i] means the max profit from i to the end
        vector<int> memo(n, -1);
        return dfs(startTime, endTime, profit, n, 0, memo);
    }
};
