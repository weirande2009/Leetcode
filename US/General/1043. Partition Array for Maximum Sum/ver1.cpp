#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dfs(vector<int>& arr, vector<int>& memo, int k, int i){
        int n = arr.size();
        if(i == n){
            return 0;
        }
        if(memo[i] != -1){
            return memo[i];
        }
        int ans = 0;
        for(int j=i; j<min(i+k, n); j++){
            int mx = *max_element(arr.begin()+i, arr.begin()+j+1);
            ans = max(ans, mx*(j-i+1) + dfs(arr, memo, k, j+1));
        }
        memo[i] = ans;
        return ans;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> memo(n, -1);
        return dfs(arr, memo, k, 0);
    }
};