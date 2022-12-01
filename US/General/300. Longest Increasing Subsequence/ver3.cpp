#include <vector>
using namespace std;



class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // record[i] means the number of numbers which are less than nums[i]
        vector<int> sub = {nums[0]};
        int m = 1;
        for(int i=1; i<n; i++){
            if(nums[i] > sub[m-1]){
                sub.push_back(nums[i]);
                m++;
            }
            else{
                // find the first in sub that larger than or equal to num[i] and replaced by nums[i]
                // use binary search to find the num, because sub is a increasing array
                int low = 0;
                int high = m-1;
                while(low < high){
                    int mid = (low + high) / 2;
                    if(sub[mid] < nums[i]){
                        low = mid+1;
                    }
                    else if(sub[mid] > nums[i]){
                        high = mid-1;
                    }
                    else{
                        low = mid;
                        break;
                    }
                }
                for(int j=max(low-1, 0); j<=max(low+1, m-1); j++){
                    if(sub[j] >= nums[i]){
                        sub[j] = nums[i];
                        break;
                    }
                }
            }
        }
        return m;
    }
};