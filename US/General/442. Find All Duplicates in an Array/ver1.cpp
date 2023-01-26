#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for(int num: nums){
            int i = abs(num)-1;
            if(nums[i] > 0){
                nums[i] *= -1;
            }
            else if(nums[i] < 0){
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};