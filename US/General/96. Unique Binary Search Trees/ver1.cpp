#include <vector>
using namespace std;

// Algorithm: dp[i] means the number of unique BST in i. To compute dp[i], we can choose
// each of 1~i as the root, denoted as j. Thus, there will be 1~j-1 on the left and j+1~i
// on the right. so dp[j] = dp[j-1]*dp[i-j]; And to sum j, dp[i] = sum of dp[j].

class Solution {
public:
    int numTrees(int n) {
        if(n < 2){
            return 1;
        }
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i=2; i<=n; i++){
            for(int j=0; j<i; j++){
                dp[i] += dp[j]*dp[i-j-1];
            }
        }
        return dp[n];
    }
};