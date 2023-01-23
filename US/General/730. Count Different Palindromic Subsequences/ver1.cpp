#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int countPalindromicSubsequences(string s) {
        const int MOD = 1000000007;
        int n = s.length();
        // dp[i][j] means the number of different palindrome subsequences in substr[i, j]
        vector<vector<int>> dp(n, vector<int>(n, 0));
        // all substr of length 1 is palindromic
        for(int i=0; i<n; i++){
            dp[i][i] = 1;
        }
        for(int l=2; l<=n; l++){  // start from length of 2
            for(int i=0; i<=n-l; i++){
                // compute the end of the substring
                int j = i+l-1;
                if(s[i] == s[j]){
                    int low = i+1;
                    int high = j-1;
                    // search the first character from left that is the same as s[j] in substr[i+1, j-1]
                    while(low <= high && s[low] != s[j]){
                        low++;
                    }
                    // Then, search the first character from right that is the same as s[j] in substr[low, j-1]
                    while(low <= high && s[high] != s[j]){
                        high--;
                    }
                    // if low > high, there is no letter between i and j which is the same as s[i], so we can
                    // double the dp[i+1][j-1] because the palindrom in s[i+1, i-1] will be counted twice.
                    // Besides, there is also palindrom of s[i] and s[i]s[j]
                    if(low > high){
                        dp[i][j] = dp[i+1][j-1]*2 + 2;
                    }
                    // if low == high, there is only one letter between i and j which is the same as s[i]
                    // so we can double the dp[i+1][j-1] because the palindrom in s[i+1, i-1] will be counted
                    // twice and we still need one substring like s[i]s[i].
                    else if(low == high){
                        dp[i][j] = dp[i+1][j-1]*2 + 1;
                    }
                    // if low < high, there is at least two letters between i and j which is the same as s[i]
                    // so first we can double the dp[i+1][j-1] because the palindrom in s[i+1, i-1] will be
                    // counted twice, but there are duplicates, which are those palindromes inside s[low+1, high-1]
                    // they are wrapped by s[i]...s[j] twice by s[i]s[j] and s[low]s[high], so we should delete
                    // them
                    else{
                        dp[i][j] = dp[i+1][j-1]*2 - dp[low+1][high-1];
                    }
                }
                else{  // if s[i] != s[j]
                    dp[i][j] = dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1];
                }
                // mod
                dp[i][j] = dp[i][j] < 0 ? dp[i][j]+MOD : dp[i][j] % MOD;
            }
        }
        return dp[0][n-1];
    }
};