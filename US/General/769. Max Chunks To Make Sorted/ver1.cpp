#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int mx = -1;
        int count = 0;
        for(int i=0; i<n; i++){
            // compute the current max number
            mx = max(mx, arr[i]);
            // if the max current number is equal to the index, then this is a chunk
            if(mx == i){
                count++;
            }
        }
        return count;
    }
};