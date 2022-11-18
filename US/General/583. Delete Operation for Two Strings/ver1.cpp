#include <vector>
#include <string>
using namespace std;

// Algorithm: look this problem as the reversed version of the max match in two words

class Solution {
public:
    int minDistance(string word1, string word2) {
        int l1 = word1.length();
        int l2 = word2.length();
        // dp[i][j] means the length of the longest match of word1[i:] and word2[j:]
        vector<vector<int>> dp(l1+1, vector<int>(l2+1, 0));
        for(int i=l1-1; i>=0; i--){
            for(int j=l2-1; j>=0; j--){
                if(word1[i] == word2[j]){
                    dp[i][j] = 1 + dp[i+1][j+1];
                }
                else{
                    dp[i][j] = max(dp[i][j+1], dp[i+1][j]);
                }
            }
        }
        
        return l1+l2-2*dp[0][0]; 
    }
};