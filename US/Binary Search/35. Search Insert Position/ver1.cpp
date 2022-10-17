#include <vector>
using namespace std;


class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        while(low < high){
            int mid = (low+high)/2;
            if(nums[mid] > target){
                high = mid-1;
            }
            else if(nums[mid] < target){
                low = mid+1;
            }
            else{
                return mid;
            }
        }
        if(nums[low] >= target){
            return low;
        }
        else{
            return low+1;
        }
        
    }
};