#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        // dp[i] means the minimum number of clips to run through time i
        vector<int> dp(time+1, INT_MAX);
        sort(clips.begin(), clips.end(), [](const vector<int>& v1, const vector<int>& v2){
            return v1[0] < v2[0];
        });
        dp[0] = 0;
        for(const auto& clip: clips){
            if(clip[0] >= time){
                break;
            }
            int last = clip[0];
            if(dp[last] == INT_MAX){
                return -1;
            }
            for(int i=clip[0]+1; i<=min(clip[1], time); i++){
                dp[i] = min(dp[last]+1, dp[i]);
            }
        }
        return dp[time] == INT_MAX ? -1 : dp[time];
    }
};