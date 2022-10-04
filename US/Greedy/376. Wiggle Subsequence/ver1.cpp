#include <vector>
using namespace std;

// Algorithm: O(n). Use greedy to traverse all the number. For each element, judge
// nums[i] > nums[i-1] or and current state of finding bigger or smaller. When they
// match it's a valid number. Then change the current state and find the next.

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if(n == 2){
            if(nums[0] != nums[1]){
                return 2;
            }
            else{
                return 1;
            }
        }
        else if(n == 1){
            return 1;
        }
        int type = 0;
        int l = 1;
        for(int i=1; i<n; i++){
            if(type == 0){
                if(nums[i] > nums[0]){
                    type = -1;
                    l++;
                }
                else if(nums[i] < nums[0]){
                    type = 1;
                    l++;
                }
            }
            if((nums[i] - nums[i-1])*type > 0){
                type *= -1;
                l++;
            }
        }
        return l;
    }
};