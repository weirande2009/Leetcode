#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        vector<int> test = {1,2,3, 9};
        auto testit = upper_bound(test.begin()+3, test.end(), 8);

        int n = pairs.size();
        // sort by left
        sort(pairs.begin(), pairs.end(), [](const vector<int>& v1, const vector<int>& v2){
            return v1[0] < v2[0];
        });
        // dp[i] means the max length of pair chain of pairs[i:]
        vector<int> dp(n, 0);
        dp[n-1] = 1;
        for(int i=n-2; i>=0; i--){
            auto it = upper_bound(pairs.begin()+i+1, pairs.end(), pairs[i], [](const vector<int>& v, const vector<int>& e){
                return e[0] > v[1];
            });
            if(it == pairs.end()){
                dp[i] = dp[i+1];
            }
            else{
                dp[i] = max(dp[i+1], dp[it-pairs.begin()]+1);
            }
        }
        return dp[0];
    }
};