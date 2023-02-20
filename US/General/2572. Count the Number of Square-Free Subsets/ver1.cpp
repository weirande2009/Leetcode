#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int memo[1001][1024];
    vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    int MOD = 1e9 + 7;

public:
    // find the number of square-free subsets when consider the nums of [i:] with mask
    int dp(vector<int>& nums, int i, int mask){
        if(i == nums.size()){
            return 1;
        }
        if(memo[i][mask] != -1){
            return memo[i][mask];
        }
        // check whether nums[i] is valid in the condition of mask and compute the mask including nums[i]
        bool valid = true;
        int new_mask = mask;
        for(int j=0; j<10; j++){
            int count = 0;
            int tmp = nums[i];
            while(tmp % primes[j] == 0 && tmp > 0){
                count++;
                tmp /= primes[j];
            }
            // if there are more than one prime as the factor or the prime exists in mask
            if(count > 1 || (count == 1 && (mask >> j & 1))){
                valid = false;
                break;
            }
            if(count == 1){
                new_mask |= (1 << j);
            }
        }
        if(valid){
            memo[i][mask] = (dp(nums, i+1, new_mask) + dp(nums, i+1, mask)) % MOD;
        }
        else{
            memo[i][mask] = dp(nums, i+1, mask);
        }
        return memo[i][mask];
    }

    int squareFreeSubsets(vector<int>& nums) {
        memset(memo, -1, sizeof(memo));
        return dp(nums, 0, 0) - 1;  // -1 because here include the case of selecting nothing
    }
};