#include <vector>
#include <limits.h>
using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> middle;
        int n = nums.size();
        if(n < 3){
            return false;
        }
        int mn = INT_MAX;
        int middle_mn = INT_MAX;
        for(int i=0; i<n; i++){
            mn = min(mn, nums[i]);
            if(nums[i] > mn){
                middle_mn = min(middle_mn, nums[i]);
            }
            if(nums[i] > middle_mn){
                return true;
            }
        }
        return false;
    }
};