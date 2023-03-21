#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        int continuous = 0;
        for(int i=0; i<n; i++){
            if(nums[i] == 0){
                continuous++;
            }
            else{
                continuous = 0;
            }
            ans += continuous;
        }
        return ans;
    }
};