#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int m = strs.size();
        int n = strs[0].size();
        int count = 0;
        // sorted[i] means that strs[i] < strs[i+1] is gotten
        vector<bool> sorted(n, false);
        for(int i=0; i<n; i++){
            bool deleted = false;
            for(int j=0; j<m-1; j++){
                if(!sorted[j] && strs[j][i] > strs[j+1][i]){
                    count++;
                    deleted = true;
                    break;
                }
            }
            if(!deleted){  // we don't need to delete current column, there may be new sorted strings
                // recompute the sorted array
                for(int j=0; j<m-1; j++){
                    sorted[j] = sorted[j] || strs[j][i] < strs[j+1][i];
                }
            }
        }
        return count;
    }
};