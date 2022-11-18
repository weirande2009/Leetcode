#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        int l_s = s.length();
        int l_t = t.length();
        if(l_s < l_t){
            return 0;
        }
        // dp[i][j] means the number of subsequence match the problem between s[i:] and t[j:]
        vector<vector<long long>> dp(l_s+1, vector<long long>(l_t+1, 0));
        
        for(int i=0; i<=l_s; i++){
            dp[i][l_t] = 1;
        }
        for(int i=l_s-1; i>=0; i--){
            for(int j=l_t-1; j>=0; j--){
                dp[i][j] = dp[i+1][j];
                if(s[i] == t[j]){
                    dp[i][j] += dp[i+1][j+1];
                }
            }
        }
        
        return dp[0][0];
    }
};