#include <cmath>
#include <vector>
using namespace std;

// Algorithm: DP. dp[i] means the least steps from dp[n] to dp[i]. For each i, compute the 
// max root. And compute each left subtracting from 1 to max root and reset the dp[left].


class Solution {
public:
    int numSquares(int n) {
        
        vector<int> dp(n+1, 0);
        // Intialize dp as the worse case(all 1)
        for(int i=0; i<n+1; i++){
            dp[i] += n-i;
        }
        for(int i=n; i>=0; i--){
            // subtract the biggest perfect square number
            int max_root = (int)sqrt(i);
            for(int j=1; j<=max_root; j++){
                int left = i-j*j;
                if(dp[left] > dp[i]+1){
                    dp[left] = dp[i]+1;
                }
            }
            
        }
        return dp[0];
    }
};