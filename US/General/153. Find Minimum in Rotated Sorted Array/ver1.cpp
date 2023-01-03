#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        while(low < high){
            int mid = (low+high) / 2;
            if(nums[mid] < nums[low]){
                high = mid-1;
            }
            else if(nums[mid] > nums[high]){
                low = mid+1;
            }
            else{
                break;
            }
        }
        return min(nums[low], nums[(high+1)%n]);
    }
};