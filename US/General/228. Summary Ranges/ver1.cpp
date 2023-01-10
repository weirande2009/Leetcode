#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        int begin = 0;
        int n = nums.size();
        if(n == 0){
            return {};
        }
        for(int i=1; i<n; i++){
            if((long long)nums[i]-nums[i-1] != 1){
                if(i-1 == begin){
                    result.push_back(to_string(nums[begin]));
                }
                else{
                    result.push_back(to_string(nums[begin])+"->"+to_string(nums[i-1]));
                }
                begin = i;
            }
        }
        if(n-1 == begin){
            result.push_back(to_string(nums[begin]));
        }
        else{
            result.push_back(to_string(nums[begin])+"->"+to_string(nums[n-1]));
        }
        return result;
    }
};