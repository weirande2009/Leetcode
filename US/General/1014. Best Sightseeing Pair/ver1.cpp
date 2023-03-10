#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        int cur = values[0]-1;
        int ans = 0;
        for(int i=1; i<n; i++){
            ans = max(ans, cur + values[i]);
            cur = max(cur, values[i]) - 1;
        }
        return ans;
    }
};