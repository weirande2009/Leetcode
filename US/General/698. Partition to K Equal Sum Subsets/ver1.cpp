#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dp(vector<int>& nums, string& taken, int index, int count, int sum, int k, int target, unordered_map<string, bool>& memo){
        int n = nums.size();

        // if the current subset number is k-1, the left subset must have a sum of target
        if(count == k-1){
            return true;
        }

        // if the current sum is greater than target, return false
        if(sum > target){
            return false;
        }

        if(memo.find(taken) != memo.end()){
            return memo[taken];
        }

        if(sum == target){
            // go to the next count from beginning
            return dp(nums, taken, 0, count+1, 0, k, target, memo);
        }
        
        for(int i=index; i<n; i++){
            if(taken[i] == '0'){  // if nums[i] is not taken
                taken[i] = '1';

                if(dp(nums, taken, i+1, count, sum+nums[i], k, target, memo)){
                    return true;  // only need one of the possible combinations to be true
                }

                taken[i] = '0';
            }
        }
        memo[taken] = false;
        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % k != 0){
            return false;
        }
        int target = sum / k;
        if(*max_element(nums.begin(), nums.end()) > target){
            return false;
        }
        int n = nums.size();
        unordered_map<string, bool> memo;
        string taken(n, '0');
        return dp(nums, taken, 0, 0, 0, k, target, memo);
    }
};