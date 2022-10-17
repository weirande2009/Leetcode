#include <vector>
using namespace std;

// Algorithm: Use binary search to find the first index and use another BS to find the 
// last index.

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = -1;
        int right = -1;
        int n = nums.size();
        int low = 0;
        int high = n-1;
        // Find low
        while(low <= high){
            int mid = (low+high)/2;
            if(nums[mid] > target){
                high = mid-1;
            }
            else if(nums[mid] < target){
                low = mid+1;
            }
            else{
                if(mid == 0 || nums[mid-1] < target){
                    left = mid;
                    break;
                }
                high = mid-1;
            }
        }
        low = 0;
        high = n-1;
        // Find high
        while(low <= high){
            int mid = (low+high)/2;
            if(nums[mid] > target){
                high = mid-1;
            }
            else if(nums[mid] < target){
                low = mid+1;
            }
            else{
                if(mid == n-1 || nums[mid+1] > target){
                    right = mid;
                    break;
                }
                low = mid+1;
            }
        }
        return {left, right};
    }
};