#include <vector>
using namespace std;

class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int n = nums.size();
        vector<int> new_nums(n);
        int odd_num = 0;
        int even_num = 0;
        for(int i=0; i<n; i++){
            if(nums[i] % 2){  // if odd
                new_nums[odd_num] = nums[i];
                odd_num++;
            }
            else{
                new_nums[n-even_num-1] = nums[i];
                even_num++;
            }
        }
        return new_nums;
    }
};

