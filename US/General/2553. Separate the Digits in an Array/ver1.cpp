#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for(int i=0; i<n; i++){
            string s = to_string(nums[i]);
            for(char c: s){
                ans.push_back(c-'0');
            }
        }
        return ans;
    }
};