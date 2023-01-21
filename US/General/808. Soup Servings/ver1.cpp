#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    double soupServings(int n) {
        // if n is big enough, just return 1
        if(n > 4800){
            return 1;
        }
        // we take 25 as a serving and compute the number of servings in n
        n = ceil((float)n/25);
        // dp[i][j] means the probability of remain i servings of A and j servings of B
        vector<vector<float>> dp(n+4, vector<float>(n+4, 0));
        dp[n+3][n+3] = 1;
        for(int i=n+3; i>3; i--){
            for(int j=n+3; j>3; j--){
                dp[i-4][j] += 0.25 * dp[i][j];
                dp[i-3][j-1] += 0.25 * dp[i][j];
                dp[i-2][j-2] += 0.25 * dp[i][j];
                dp[i-1][j-3] += 0.25 * dp[i][j];
            }
        }
        float ans = 0;
        // add only A come to 0
        for(int i=0; i<4; i++){
            for(int j=4; j<n+4; j++){
                ans += dp[i][j];
            }
        }
        // add both come to 0
        for(int i=0; i<4; i++){
            for(int j=0; j<4; j++){
                ans += 0.5*dp[i][j];
            }
        }
        return ans;
    }
};