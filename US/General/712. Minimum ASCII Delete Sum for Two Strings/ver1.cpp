#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int l1 = s1.length();
        int l2 = s2.length();
        // dp[i][j] means the minimum delete sum for s1[:i] and s2[:j] to be equal
        vector<vector<int>> dp(l1, vector<int>(l2, 0));
        // initial
        if(s1[0] == s2[0]){
            dp[0][0] = 0;
        }
        else{
            dp[0][0] = s1[0] + s2[0];
        }
        int sum = s1[0];
        for(int i=1; i<l1; i++){
            if(s1[i] == s2[0]){
                dp[i][0] = sum;
            }
            else{
                dp[i][0] = dp[i-1][0] + s1[i];
            }
            sum += s1[i];
        }
        sum = s2[0];
        for(int i=1; i<l2; i++){
            if(s2[i] == s1[0]){
                dp[0][i] = sum;
            }
            else{
                dp[0][i] = dp[0][i-1] + s2[i];
            }
            sum += s2[i];
        }
        for(int i=1; i<l1; i++){
            for(int j=1; j<l2; j++){
                if(s1[i] == s2[j]){
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j]+s1[i], dp[i][j-1]+s2[j]));
                }
                else{
                    dp[i][j] = min(dp[i-1][j-1]+s1[i]+s2[j], min(dp[i-1][j]+s1[i], dp[i][j-1]+s2[j]));
                }
            }
        }
        return dp[l1-1][l2-1];
    }
};