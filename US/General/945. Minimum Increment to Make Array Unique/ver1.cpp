#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int count = 0;
        for(int i=1; i<n; i++){
            int incre = nums[i-1]-nums[i] >= 0 ? nums[i-1]-nums[i]+1 : 0;
            nums[i] += incre;
            count += incre;
        }
        return count;
    }
};