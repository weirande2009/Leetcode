#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        // dp[i][j] means the length of fib in arr[i:j] inclusively
        vector<vector<int>> dp(n, vector<int>(n, 2));
        // key-number, value-index
        unordered_map<int, int> hashtable;
        for(int i=0; i<n; i++){
            hashtable[arr[i]] = i;
        }
        int ans = 0;
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                int x = arr[i] - arr[j];
                if(hashtable.find(x) != hashtable.end() && hashtable[x] < j){
                    dp[j][i] = max(dp[j][i], dp[hashtable[x]][j]+1);
                }
                ans = max(ans, dp[j][i]);
            }
        }
        return ans <= 2 ? 0 : ans;
    }
};