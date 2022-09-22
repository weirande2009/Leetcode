#include <vector>
using namespace std;

// Algorithm: Use an array dp to record the minimum step to each element in nums.
// So dp[i] means the minimum steps from 0 to i. So for each nums[i], given j from last farthest index to 
// nums[i]+1, set dp[j] = dp[i] + 1, because we need only one step from i to each j. And record
// the farthest index. This farthest index constrain the minimum step. 


class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        // dp[i] means the minimum steps from 0 to i
        vector<int> dp(n, n+1);
        dp[0] = 0;
        int farthest_index = 0;
        for(int i=0; i<n; i++){
            for(int j=farthest_index+1; j<=nums[i]+i; j++){
                if(j > n-1){
                    break;
                }
                dp[j] = dp[i] + 1;
            }
            if(i+nums[i] > farthest_index){
                farthest_index = i+nums[i];
            }
            if(farthest_index >= n-1){
                return dp[n-1];
            }
        }
        return dp[n-1];
    }
};

int main(){
    vector<int> nums = {2,3,1,1,4};
    Solution s;
    s.jump(nums);



}