#include <vector>
#include <string>
using namespace std;



class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        if(s[0] == '0'){
            return 0;
        }
        // dp[i] means the number of ways to decode from 0 to i-1
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i=2; i<n+1; i++){
            if(s[i-1] == '0'){
                if(s[i-2] > '2' || s[i-2] == '0'){
                    return 0;
                }
                dp[i] = dp[i-2];
            }
            else if(s[i-2] > '2' || s[i-2] == '0' || s[i-2] == '2' && s[i-1] > '6'){
                dp[i] = dp[i-1];
            }
            else{
                dp[i] = dp[i-2] + dp[i-1];
            }
        }
        return dp[n];
    }
};