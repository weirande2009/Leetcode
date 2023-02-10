#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        stack<int> s;  // this is a monotonical stack
        const int MOD = 1000000007;
        long long ans = 0;
        for(int i=0; i<=n; i++){
            // we also add i == n to the loop, because when we add all to stack and finish in the n-1,
            // there still may be some in the stack, which is the minimum of the all array
            while(!s.empty() && (i == n || arr[s.top()] >= arr[i])){
                // now, the top of the stack means it's the minimum between (s.next_top, i)
                int local_min = s.top();
                s.pop();
                // compute the left and right boundary
                int left = s.empty() ? -1 : s.top();
                int right = i;
                long long count = (local_min-left) * (right-local_min) % MOD;
                ans = (ans + count*arr[local_min]%MOD) % MOD;
            }
            // push s to stack
            s.push(i);
        }
        return ans;
    }
};