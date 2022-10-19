#include <vector>
using namespace std;

// Algorithm: Binary search. At each time, we get nums[mid]. Then, we try to find the bigger
// neighbour of nums[mid]. If bigger, move to that direction because there must be a peak in 
// that direction.

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return 0;
        }
        if(nums[0] > nums[1]){
            return 0;
        }
        if(nums[n-1] > nums[n-2]){
            return n-1;
        }
        int low = 1;
        int high = n-2;
        while(low < high){
            int mid = (low+high)/2;
            // Judge larger than left
            if(nums[mid] < nums[mid-1]){
                high = mid-1;
            }
            else if(nums[mid] < nums[mid+1]){
                low = mid+1;
            }
            else{
                return mid;
            }
        }
        return low;
    }
};