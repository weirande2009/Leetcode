#include <vector>
using namespace std;

// Algorithm: O(n). First, calculate the number of three colors. Then, traverse the array.
// We separate the array into 3 regions according to the number of three colors. We need to
// adjust the number which is not in their region by exchange the number to the first uncertain
// index of their region and recheck the new exchanged number.

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        vector<int> nums_color(3, 0);
        for(int i=0; i<n; i++){
            nums_color[nums[i]]++;
        }
        nums_color[1] += nums_color[0];
        nums_color[2] += nums_color[1];
        vector<int> color_begin = {0, nums_color[0], nums_color[1]};
        for(int i=0; i<n; i++){
            for(int j=0; j<3; j++){
                if(i < nums_color[j]){  // part j
                    if(nums[i] != j){
                        int tmp = nums[i];
                        nums[i] = nums[color_begin[tmp]];
                        nums[color_begin[tmp]] = tmp;
                        color_begin[tmp]++;
                        i--;
                    }
                    else{
                        color_begin[j]++;
                    }
                    break;
                }
            }
        }
    }
};