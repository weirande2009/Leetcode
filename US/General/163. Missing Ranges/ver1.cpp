#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        if(n == 0){
            if(lower == upper){
                return {to_string(lower)};
            }
            else{
                return {to_string(lower)+"->"+to_string(upper)};
            }
        }
        else if(n == upper-lower+1){
            return {};
        }
        vector<string> result;
        if(nums[0] - lower == 1){
            result.push_back(to_string(lower));
        }
        else if(nums[0] - lower > 1){
            result.push_back(to_string(lower)+"->"+to_string(nums[0]-1));
        }
        for(int i=1; i<n; i++){
            if(nums[i] - nums[i-1] == 2){
                result.push_back(to_string(nums[i-1]+1));
            }
            else if(nums[i] - nums[i-1] > 2){
                result.push_back(to_string(nums[i-1]+1)+"->"+to_string(nums[i]-1));
            }
        }
        if(upper - nums[n-1] == 1){
            result.push_back(to_string(upper));
        }
        else if(upper - nums[n-1] > 1){
            result.push_back(to_string(nums[n-1]+1)+"->"+to_string(upper));
        }
        return result;
    }
};