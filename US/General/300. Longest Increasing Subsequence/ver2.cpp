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
                for(int j=0; j<m; j++){
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