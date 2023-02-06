#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        for(int i=0; i<n; i++){
            for(int j=1; j<n; j++){
                if(nums[(i+j)%n] > nums[i]){
                    ans[i] = nums[(i+j)%n];
                    break;
                }
            }
        }
        return ans;
    }
};
