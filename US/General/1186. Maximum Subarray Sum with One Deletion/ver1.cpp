#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        vector<int> max_end_here(n, 0);
        int mx = arr[0];
        max_end_here[0] = arr[0];
        for(int i=1; i<n; i++){
            // compute the sum until now and will only record the greater than 0
            max_end_here[i] = max(arr[i], max_end_here[i-1]+arr[i]);
            mx = max(mx, max_end_here[i]);
        }
        vector<int> max_start_here(n, 0);
        max_start_here[n-1] = arr[n-1];
        for(int i=n-2; i>=0; i--){
            // compute the sum until now and will only record the greater than 0
            max_start_here[i] = max(arr[i], max_start_here[i+1]+arr[i]);
        }
        // until now, we have considered all conditions of non-deletion
        // delete i-th number is the same as that we only sum the subarray end at i-1 and begin at i+1
        for(int i=1; i<n-1; i++){
            mx = max(mx, max_end_here[i-1]+max_start_here[i+1]);
        }
        return mx;
    }
};