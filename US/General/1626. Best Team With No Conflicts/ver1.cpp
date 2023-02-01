#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int, int>> pairs;
        int n = scores.size();
        for(int i=0; i<n; i++){
            pairs.push_back({scores[i], ages[i]});
        }
        sort(pairs.begin(), pairs.end(), [](const pair<int, int>& p1, const pair<int, int>& p2){
            return p1.second == p2.second ? p1.first < p2.first : p1.second < p2.second;
        });
        // dp[i] means the maximum score if i is in the team
        vector<int> dp(n, 0);
        int ans = 0;
        for(int i=0; i<n; i++){
            dp[i] = pairs[i].first;
            ans = max(ans, dp[i]);
        }
        for(int i=0; i<n; i++){
            for(int j=i-1; j>=0; j--){  // find from i-1 to 0 which consists of the max from 0 to j
                if(pairs[j].first <= pairs[i].first){
                    dp[i] = max(dp[i], dp[j]+pairs[i].first);
                }
            }
            ans = max(dp[i], ans);
        }
        return ans;
    }
};