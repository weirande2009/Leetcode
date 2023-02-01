#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        nums.push_back(1000000007);
        int n = nums.size();
        int begin = 0;
        int begin2 = -1;
        bool flag = false;
        int ans = 0;
        for(int i=1; i<n; i++){
            if(nums[i] == nums[begin]+1){
                if(!flag){
                    flag = true;
                    begin2 = i;
                }
            }
            else if(nums[i] > nums[begin]){
                if(flag){
                    ans = max(ans, i-begin);
                    if(nums[i] == nums[begin2]+1){
                        begin = begin2;
                        begin2 = i;
                    }
                    else{
                        flag = false;
                        begin = i;
                    }
                }
                else{
                    begin = i;
                }
            }
        }
        return ans;
    }
};