#include <vector>
using namespace std;

// Algorithm: O(n), use dynamic programming, use a vector dp which length is n. dp[i] means
// there is a way from 0 to i. Traverse the array, if dp[i] == true, set dp according to nums[i].
// One trick is that, use a variable to record the farthest index that is set to true in dp,
// so that there will not be 

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        // dp[i] == true means that there is a way to nums[i].
        vector<bool> dp(n, false);
        dp[0] = true;
        int farthest_index = 0;
        for(int i=0; i<n-1; i++){
            if(dp[i]){
                for(int j=farthest_index; j<=i+nums[i]; j++){
                    if(j <= n-1){
                        dp[j] = true;
                    }
                }
                if(nums[i]+i > n-1){
                    return true;
                }
                else{
                    farthest_index = nums[i]+i;
                }
            }
        }
        return dp[n-1];
    }
};
