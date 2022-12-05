#include <vector>
#include <limits.h>
#include <numeric>
using namespace std;


class Solution {
public:
    // each time of the recursion, compute the min of the max sum of k subarrays from pos to the end
    int dfs(vector<int>& nums, vector<vector<int>>& memo, int k, int pos, int n, int left){
        if(k == 1){
            return left;
        }
        if(memo[pos][k] != -1){
            return memo[pos][k];
        }
        int mn = INT_MAX;
        int sum = 0;
        for(int i=pos; i<n-k+1; i++){
            sum += nums[i];
            mn = min(mn, max(sum, dfs(nums, memo, k-1, i+1, n, left-sum)));
        }
        memo[pos][k] = mn;
        return mn;
    }
    
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int left = accumulate(nums.begin(), nums.end(), 0);
        // memo[i][j] means the largest sum from i to n with j subarrays
        vector<vector<int>> memo(n, vector<int>(k+1, -1));
        return dfs(nums, memo, k, 0, n, left);
    }
};