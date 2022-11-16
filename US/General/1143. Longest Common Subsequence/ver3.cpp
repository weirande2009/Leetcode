#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int l1 = text1.length();
        int l2 = text2.length();
        // dp[i][j] means the max common subsequence of text1[i:l1] and text2[j:l2]
        vector<vector<int>> dp(l1+1, vector<int>(l2+1, 0));
        for(int i=0; i<=l1; i++){
            dp[i][l2] = 0;
        }
        for(int i=0; i<=l2; i++){
            dp[l1][0] = 0;
        }
        for(int i=l1-1; i>=0; i--){
            for(int j=l2-1; j>=0; j--){
                // if the first char of each string is the same, it must be an optimal
                if(text1[i] == text2[j]){
                    dp[i][j] = 1 + dp[i+1][j+1];
                }
                else{
                    dp[i][j] = max(dp[i][j+1], dp[i+1][j]);
                }
            }
        }
        
        return dp[0][0];
    }
};