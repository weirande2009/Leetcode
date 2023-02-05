#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<vector<int>> ath;
        int n = score.size();
        for(int i=0; i<n; i++){
            ath.push_back({score[i], i});
        }
        sort(ath.begin(), ath.end(), [](const vector<int>& v1, const vector<int>& v2){
            return v1[0] > v2[0];
        });
        vector<string> ans(n);
        for(int i=0; i<n; i++){
            if(i == 0){
                ans[ath[i][1]] = "Gold Medal";
            }
            else if(i == 1){
                ans[ath[i][1]] = "Silver Medal";
            }
            else if(i == 2){
                ans[ath[i][1]] = "Bronze Medal";
            }
            else{
                ans[ath[i][1]] = to_string(i+1);
            }
        }
        return ans;
    }
};