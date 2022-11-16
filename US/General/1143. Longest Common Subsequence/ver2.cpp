#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    int commonSub(vector<vector<int>>& dp, string& text1, string& text2, int p1, int p2){
        // Check whether it's out of bound
        if(p1 >= text1.length() || p2 >= text2.length()){
            return 0;
        }
        // Check whether or not the subproblem has been solved
        if(dp[p1][p2] != -1){
            return dp[p1][p2];
        }
        // if the first char of each string is the same, it must be an optimal
        if(text1[p1] == text2[p2]){
            dp[p1][p2] = 1 + commonSub(dp, text1, text2, p1+1, p2+1);
        }
        else{
            // if the text1[p1] is in the optimal solution
            int option1 = commonSub(dp, text1, text2, p1, p2+1);
            // if the text1[p1] is not in the optimal solution
            int option2 = commonSub(dp, text1, text2, p1+1, p2);
            // the bigger one is the answer in the subproblem
            dp[p1][p2] = max(option1, option2);
        }
        return dp[p1][p2];
    }
    
    
    int longestCommonSubsequence(string text1, string text2) {
        int l1 = text1.length();
        int l2 = text2.length();
        // dp[i][j] means the max common subsequence of text1[i:l1] and text2[j:l2]
        vector<vector<int>> dp(l1, vector<int>(l2, -1));
        
        return commonSub(dp, text1, text2, 0, 0);
    }
};