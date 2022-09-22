#include <vector>
using namespace std;

class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int n = nums.size();
        if(n < 2){
            return nums;
        }
        int i = 0;
        int j = n-1;
        while(1){
            // find left first even
            while(i < n){
                if(nums[i] % 2 == 0){
                    break;
                }
                i++;
            }
            // find right first odd
            while(j >= 0){
                if(nums[j] % 2 != 0){
                    break;
                }
                j--;
            }
            if(j - i < 1){  // if i meets j, break
                break;
            }
            int tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;
        }
        return nums;
    }
};

