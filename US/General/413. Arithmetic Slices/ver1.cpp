#include <vector>
using namespace std;


class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if(n < 3){
            return 0;
        }
        int dif = nums[1] - nums[0];
        int count = 2;
        int result = 0;
        for(int i=2; i<n; i++){
            if(nums[i] - nums[i-1] == dif){
                count++;
                if(count == 3){
                    result += 1;
                }
                // a new element will add count-2 number of subarrays
                else if(count > 3){
                    result += count-2;
                }
            }
            else{
                count = 2;
                dif = nums[i] - nums[i-1];
            }
        }
        return result;
    }
};