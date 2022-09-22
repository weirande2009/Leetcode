#include <vector>
using namespace std;

// Algorithm: O(logn), First, use binary search to find the smallest number's index in array:
// if mid > hi, then smallest number must in the right part, or it must in left part.
// After we get the index of smallest index, we use binary search to find target number,
// when computing mid index, use the index of smallest number to adjust it to the right index.

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        // Use binary search to find the smallest number
        int lo = 0;
        int hi = n - 1;
        int mid;
        while(lo < hi){
            int mid = (lo + hi) / 2;
            if(nums[mid] > nums[hi]){
                lo = mid + 1;
            }
            else{
                hi = mid;
            }
        }
        int smallest_index = lo;
        lo = 0;
        hi = n - 1;
        // Use the index above to adjust the lo and hi when bnary search
        int index = -1;
        while(lo < hi){
            mid = (lo + hi) / 2;
            int real_mid = (mid + smallest_index) % n;
            if(nums[real_mid] == target){
                index = real_mid;
                break;
            }
            else if(nums[real_mid] > target){
                hi = mid;
            }
            else{
                lo = mid + 1;
            }
        }
        if(index == -1){
            if(nums[(lo + smallest_index) % n] == target){
                return (lo + smallest_index) % n;
            }
            else{
                return -1;
            }
        }
        return index;
    }
};


