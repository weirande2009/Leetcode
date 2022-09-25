#include <string>
#include <vector>
using namespace std;

// Algorithm: DP. dp[i][j] means s3[i+j-1] is an interleafing of s1[i-1] and s2[j-1].
// And if we say dp[i][j] is true, dp[i-1][j] should be true and s1[i-1] == s3[i+j-1] or
// dp[i][j-1] should be true and s2[j-1] == s3[i+j-1].

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.length();
        int n2 = s2.length();
        int n3 = s3.length();
        if(n1 + n2 != n3){
            return false;
        }
        vector<vector<bool>> dp(n1+1, vector<bool>(n2+1, false));
        for(int i=0; i<n1+1; i++){
            for(int j=0; j<n2+1; j++){
                if(i == 0 && j == 0){
                    dp[i][j] = true;
                }
                else if(i == 0){
                    dp[i][j] = dp[i][j-1] && s2[j-1] == s3[i+j-1];
                }
                else if(j == 0){
                    dp[i][j] = dp[i-1][j] && s1[i-1] == s3[i+j-1];
                }
                else{
                    dp[i][j] = dp[i][j-1] && s2[j-1] == s3[i+j-1] || dp[i-1][j] && s1[i-1] == s3[i+j-1];
                }
            }
        }
        return dp[n1][n2];
        
    }
};