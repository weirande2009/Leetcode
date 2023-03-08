#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        // always begin and end with 1
        vector<int> cum_nums;
        int target = 1;
        int count = 0;
        for(int i=0; i<n; i++){
            if(nums[i] == target){
                count++;
            }
            else{
                cum_nums.push_back(count);
                count = 1;
                target = nums[i];
            }
        }
        cum_nums.push_back(count);
        if(target == 0){
            cum_nums.push_back(0);
        }
        int ans = 0;
        n = cum_nums.size();
        for(int i=0; i<n; i+=2){
            ans = max(ans, cum_nums[i]);
        }
        for(int i=1; i<n-1; i+=2){
            if(cum_nums[i] == 1){
                ans = max(ans, cum_nums[i-1]+cum_nums[i+1]+1);
            }
            else{
                ans = max(ans, max(cum_nums[i-1], cum_nums[i+1])+1);
            }
        }
        return ans-1;
    }
};