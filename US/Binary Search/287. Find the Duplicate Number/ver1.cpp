#include <vector>
using namespace std;

// Algorithm: we count how many number in nums are less or equal to i from 1 to n.
// And the count if a non-decreasing array. Then, we compare the count with i, because
// in nums, if the number of numbers which are <= i, is > i, then there must be some
// duplicates <= i. And all the number >= i, the number will all > i. So We can use a
// binary search to find the first which count > i.

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int low = 1;
        int high = n;
        while(low < high){
            int mid = (low+high) / 2;
            int count = 0;
            for(int i=0; i<n; i++){
                if(nums[i] <= mid){
                    count++;
                }
            }
            if(count > mid){
                high = mid;
            }
            else{
                low = mid+1;
            }
        }
        return low;;
    }
};