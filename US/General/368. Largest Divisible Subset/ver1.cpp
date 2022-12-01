#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        // dp[i] means the number of subsets that i is in before i
        vector<int> dp(n, 1);
        vector<vector<int>> memo(n, vector<int>());
        for(int i=0; i<n; i++){
            memo[i].push_back(nums[i]);
        }
        int mx = 1;
        int pos = 0;
        for(int i=1; i<n; i++){
            int k = -1;
            for(int j=0; j<i; j++){
                if(nums[i] % nums[j] == 0){
                    if(dp[j]+1 > dp[i]){
                        dp[i] = dp[j]+1;
                        k = j;
                    }
                }
            }
            if(k != -1){
                memo[i].insert(memo[i].end(), memo[k].begin(), memo[k].end());
                if(dp[i] > mx){
                    mx = dp[i];
                    pos = i;
                }
            }
        }
        return memo[pos];
    }
};