#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        int begin = -1;
        int min_last_pos = -1;
        int max_last_pos = -1;
        long long count = 0;
        for(int i=0; i<n; i++){
            if(nums[i] < minK || nums[i] > maxK){
                begin = i;
                min_last_pos = -1;
                max_last_pos = -1;
            }
            else{
                // update last min and max
                min_last_pos = nums[i] == minK ? i : min_last_pos;
                max_last_pos = nums[i] == maxK ? i : max_last_pos;
                // if there are both min and max, count the number of subarray end at i
                if(min_last_pos != -1 && max_last_pos != -1){
                    count += min(min_last_pos, max_last_pos) - begin;
                }
            }
        }
        return count;
    }
};