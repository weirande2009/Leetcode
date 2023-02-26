#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        int n = nums.size();
        // there are at most n/2 pairs, so we first sort the array, then divide the array
        // into two part and search them greedily.
        sort(nums.begin(), nums.end());
        int count = 0;
        int j = (n+1) / 2;  // the index in the second array
        for(int i=0; i<n/2; i++){
            while(j < n && nums[i] * 2 > nums[j]){
                j++;
            }
            if(j < n)
                count++;
            j++;
        }
        return count*2;
    }
};