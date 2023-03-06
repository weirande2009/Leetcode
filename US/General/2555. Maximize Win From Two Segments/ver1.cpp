#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximizeWin(vector<int>& prizePositions, int k) {
        int n = prizePositions.size();
        vector<int> next_positions(n);
        auto begin_it = prizePositions.begin();
        for(int i=0; i<n; i++){
            // find the first segment
            auto first_pos = upper_bound(begin_it, prizePositions.end(), prizePositions[i]+k);
            begin_it = first_pos;
            next_positions[i] = first_pos - prizePositions.begin();
            // cout << next_positions[i] << endl;
        }
        vector<int> mx_after(n, 1);
        for(int i=n-2; i>=0; i--){
            mx_after[i] = max(mx_after[i+1], next_positions[i]-i);
            // cout << mx_after[i] << endl;
        }
        int ans = 0;
        for(int i=0; i<n; i++){
            if(next_positions[i] == n){
                ans = max(ans, mx_after[i]);
            }
            else{
                ans = max(ans, next_positions[i]-i + mx_after[next_positions[i]]);
            }
        }
        return ans;
    }
};