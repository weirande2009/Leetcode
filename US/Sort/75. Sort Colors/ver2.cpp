#include <vector>
using namespace std;

// Algorithm: O(n). Separate the array into three part, left, mid and right. left means the
// most right edge + 1 of the left part, mid means the most right edge + 1 of the mid part,
// right means the most left edge - 1 of the right part. We initialize left=mid=0, right=n-1,
// We use mid to traverse the array.
// When nums[mid] == 0, we need to swap nums[left] and nums[mid] to exchange(because left 
// point to the first 1), and mid++, left++. When nums[mid] == 1, mid++ which just expand 
// the mid part. When nums[mid] == 2, swap nums[mid] and nums[right], and right--, but don't
// change mid, because we still need to judge it in case it's also a 2, because we didn't
// check nums[n-1] to be 2.

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int mid = 0;
        int right = n-1;
        while(mid <= right){
            if(nums[mid] == 0){
                nums[mid] = 1;
                nums[left] = 0;
                mid++;
                left++;
            }
            else if(nums[mid] == 1){
                mid++;
            }
            else if(nums[mid] == 2){
                nums[mid] = nums[right];
                nums[right] = 2;
                right--;
            }
        }
    }
};