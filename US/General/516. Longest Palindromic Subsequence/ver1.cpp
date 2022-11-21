#include <string>
#include <vector>
using namespace std;


class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int l = s.length();
        // dp[i][j] means the max length of palindromic of length i+1, begin with j
        vector<vector<int>> dp(l, vector<int>(l, 0));
        for(int i=0; i<l; i++){
            dp[0][i] = 1;
        }
        for(int i=1; i<l; i++){
            for(int j=0; j<l; j++){
                // the end index of the case
                int k = j+i;
                if(k >= l){
                    break;
                }
                if(i+1 < 3){  // when length is 2
                    if(s[j] == s[k]){
                        dp[i][j] = 2;
                    }
                    else{
                        dp[i][j] = 1;
                    }
                }
                else{
                    if(s[j] == s[k]){
                        dp[i][j] = max(2 + dp[i-2][j+1], max(dp[i-1][j], dp[i-1][j+1]));
                    }
                    else{
                        dp[i][j] = max(dp[i-2][j+1], max(dp[i-1][j], dp[i-1][j+1]));
                    }
                }
            }
        }
        return dp[l-1][0];
    }
};