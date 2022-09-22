#include <vector>
#include <string>
#include <cstring>
using namespace std;

// Algorithm: Use a dp whose length is n+1. Let dp[0] = 1. Then, set dp[1] = 1 if s[0] != '0'
// else dp[1] = 0. Then start traversing string from i=1 to n-1. Judge two string s[i-1:i+1]
// and s[i-2:i+1]. Check s[i-1:i+1] is number, then dp[i] += dp[i-1]. Check s[i-2:i+1] is 
// between 10~26, then dp[i] += dp[i-2].


class Solution {
public:
    int numDecodings(string s) {
        if(s[0] == '0'){
            return 0;
        }
        int n = s.length();
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = s[0] == '0' ? 0 : 1;
        for(int i=2; i<=n; i++){
            int first = stoi(s.substr(i-1, 1));
            int second = stoi(s.substr(i-2, 2));
            if(first >= 1 && first <= 9){
                dp[i] += dp[i-1];
            }
            if(second >= 10 && second <= 26){
                dp[i] += dp[i-2];
            }
        }
        return dp[n];
    }
};