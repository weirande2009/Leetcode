#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> s;
        // use two loop from back to end to traverse the array twice, i.e. start, ..., end, start, ..., end
        for(int i=2*n+1; i>=0; i--){
            int idx = i % n;
            // clear the elements that are smaller than current one
            while(!s.empty() && nums[s.top()] <= nums[idx]){
                s.pop();
            }
            // the answer of current one is top of the stack or -1
            ans[idx] = s.empty() ? -1 : nums[s.top()];
            // push to stack
            s.push(idx);
        }
        return ans;
    }
};