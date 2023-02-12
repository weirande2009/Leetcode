#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        long long ans = 0;
        int left = 0;
        int right = nums.size()-1;
        while(left < right){
            ans += stoi(to_string(nums[left++]) + to_string(nums[right--]));
        }
        if(left == right){
            ans += nums[left];
        }
        return ans;
    }
};