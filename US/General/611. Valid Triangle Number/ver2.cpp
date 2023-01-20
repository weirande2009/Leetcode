#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int binarySearch(vector<int>& nums, int low, int high, int target){
        while(low <= high && high < nums.size()){
            int mid = low + (high-low) / 2;
            if(nums[mid] < target){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return low;
    }

    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int count = 0;
        for(int i=0; i<n-2; i++){
            int k = i+2;
            for(int j=i+1; j<n-1 && nums[i] != 0; j++){
                while(k < n && nums[i]+nums[j]>nums[k]){
                    k++;
                }
                count += k-j-1;
            }
        }
        return count;
    }
};