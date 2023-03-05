#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isOverlap(const vector<int>& v1, const vector<int>& v2){
        return v1[1] >= v2[0] && v2[1] >= v1[0];
    }
    
    vector<int> mergeRange(const vector<int>& v1, const vector<int>& v2){
        return {min(v1[0], v2[0]), max(v1[1], v2[1])};
    }
    
    int countWays(vector<vector<int>>& ranges) {
        sort(ranges.begin(), ranges.end(), [](const vector<int>& v1, const vector<int>& v2){
            return v1[0] < v2[0];
        });
        
        vector<int> cur_range = ranges[0];
        int count = 1;
        int n = ranges.size();
        for(int i=1; i<n; i++){
            if(isOverlap(cur_range, ranges[i])){
                cur_range = mergeRange(cur_range, ranges[i]);
            }
            else{
                cur_range = ranges[i];
                count++;
            }
        }
        long long ans = 1;
        const int MOD = 1e9 + 7;
        for(int i=0; i<count; i++){
            ans = (ans * 2) % MOD;
        }
        return ans;
    }
};