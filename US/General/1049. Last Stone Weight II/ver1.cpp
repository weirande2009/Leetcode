#include <vector>
#include <cmath>
using namespace std;


class Solution {
public:    
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        // This problem is the same as "divide nums into two group so that the sum of the two groups is minimized"
        // dp[i] means the the sum to i is possible, initialized as impossible
        vector<bool> dp(1501, false);
        // sum to i is possible
        dp[0] = true;
        // the max sum of stones is 3000, so to get half of the sumis the limit
        int sum = 0;
        for(int i: stones){
            sum += i;
            // between sum and i, find all possible sum, which will iterate over all
            // number in stones from start to now.
            for(int j=min(1500, sum); j>=i; j--){
                dp[j] = dp[j-i] || dp[j];
            }
        }
        // find the max i such that dp[i] is true
        for(int i=sum/2; i>=0; i++){
            if(dp[i]){
                return abs(sum-2*i);
            }
        }
        return 0;
    }
};