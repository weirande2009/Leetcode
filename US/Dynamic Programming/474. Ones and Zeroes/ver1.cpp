#include <vector>
#include <string>
using namespace std;

// Algorithm: dp[i][j][k] means the largest subset of strs such that there are at most, j 0's and 
// k 1's before and including strs[i]. 
// dp[i][j][k] = max(dp[i-1][j][k], dp[i-1][j-num0][k-num1]+1)

class Solution {
public:
    int Count(const string& strs, char c){
        int count = 0;
        for(int i=0; i<strs.length(); i++){
            if(strs[i] == c){
                count++;
            }
        }
        return count;
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        int size = strs.size();
        // dp[i][j][k] means the largest subset of strs such that there are at most, j 0's and 
        // k 1's before and including strs[i]
        vector<vector<vector<int>>> dp(size, vector<vector<int>>(m+1, vector<int>(n+1, 0)));
        int num0 = Count(strs[0], '0');
        int num1 = Count(strs[0], '1');
        for(int i=0; i<m+1; i++){
            for(int j=0; j<n+1; j++){
                if(i < num0 || j < num1){
                    dp[0][i][j] = 0;
                }
                else{
                    dp[0][i][j] = 1;
                }
            }
        }
        for(int i=1; i<size; i++){
            num0 = Count(strs[i], '0');
            num1 = Count(strs[i], '1');
            for(int j=0; j<m+1; j++){
                for(int k=0; k<n+1; k++){
                    if(j < num0 || k < num1){
                        dp[i][j][k] = dp[i-1][j][k];
                    }
                    else{
                        dp[i][j][k] = max(dp[i-1][j-num0][k-num1]+1, dp[i-1][j][k]);
                    }
                }
            }
        }
        return dp[size-1][m][n];
        
    }
};