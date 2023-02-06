#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        // dp[i] means that the lowest cost on i-th day
        vector<int> dp(days.back()+1);
        unordered_set<int> hashtable;
        for(int d: days){
            hashtable.insert(d);
        }
        for(int i=1; i<days.back()+1; i++){
            if(hashtable.find(i) != hashtable.end()){  // if the day needs travel
                dp[i] = min(dp[max(i-1, 0)]+costs[0], min(dp[max(i-7, 0)]+costs[1], dp[max(i-30, 0)]+costs[2]));
            }
            else{
                dp[i] = dp[i-1];
            }
        }
        return dp[days.back()];
    }
};