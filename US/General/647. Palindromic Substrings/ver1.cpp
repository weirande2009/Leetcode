#include <string>
#include <vector>
using namespace std;

// Algorithm: the same as find the longest palindrome, every time we find a palindrome
// count++;

class Solution {
public:
    int countSubstrings(string s) {
        int l = s.length();
        // dp[i][j] means the substring start from j with length i+1 is a palindrome
        vector<vector<bool>> dp(l, vector<bool>(l, false));
        int count = 0;
        for(int i=0; i<l; i++){
            dp[0][i] = true;
            count++;
        }
        for(int i=1; i<l; i++){
            for(int j=0; j<l; j++){
                int k = j+i;
                if(k > l-1){
                    break;
                }
                if(i+1 <= 3){
                    dp[i][j] = s[j] == s[k];
                }
                else{
                    dp[i][j] = s[j] == s[k] && dp[i-2][j+1];
                }
                if(dp[i][j]){
                    count++;
                }
            }
        }
        return count;
    }
};