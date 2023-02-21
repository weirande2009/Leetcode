#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        while(low < high){
            int mid = (low + high) / 2;
            // set the mid to the second same number
            if(mid+1 < n && nums[mid+1] == nums[mid]){
                mid += 1;
            }
            if(nums[mid] != nums[mid-1]){
                return nums[mid];
            }
            if(mid % 2 == 0){
                high = mid-2;
            }
            else{
                low = mid+1;
            }
        }
        return nums[low];

    }
};