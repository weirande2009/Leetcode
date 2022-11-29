#include <vector>
using namespace std;

class Solution {
public:
    int numWays(int n, int k) {
        if(n == 1){
            return k;
        }
        else if(n == 2){
            return k*k;
        }
        // dp[i] means the number of ways to paint the ith post
        vector<int> dp(n, 0);
        dp[0] = k;
        dp[1] = k*k;
        for(int i=2; i<n; i++){
            // when the color on ith post is different from the color on (i-1)th post
            dp[i] += (k-1) * dp[i-1];
            // when the color on ith post is the same as the color on the (i-1)th post
            // and because three color in a row is not allowed, so in this situation
            // the color of (i-1)th post must be different from (i-2)th post, so it's
            // the number of ways that (i-1)th post is different from (i-2)th post
            dp[i] += (k-1) * dp[i-2];
        }
        
        return dp[n-1];
    }
};