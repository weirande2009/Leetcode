#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dfs(vector<int>& nums, int k, vector<int>& memo, int i){
        int n = nums.size();
        if(i == n){
            return 0;
        }
        if(memo[i] != -1){
            return memo[i];
        }
        unordered_map<int, int> hashtable;
        int count = 0;
        int cost = INT_MAX;
        for(int j=i; j<n; j++){
            if(hashtable.find(nums[j]) != hashtable.end()){
                if(hashtable[nums[j]] == 1){
                    count++;
                }
                count++;
            }
            hashtable[nums[j]]++;
            cost = min(cost, k+count+dfs(nums, k, memo, j+1));
        }
        memo[i] = cost;
        return cost;
    }

    int minCost(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> memo(n, -1);
        return dfs(nums, k, memo, 0);
    }
};