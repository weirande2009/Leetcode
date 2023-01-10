#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cur_target_pos = 1;
        int cur_num = nums[0];
        int cur_n = 1;
        int n = nums.size();
        int k = 0;
        for(int i=1; i<n; i++){
            // if equal to the current number
            if(nums[i] == cur_num){
                cur_n++;
                // if the number has been over 2
                if(cur_n > 2){
                    // add to k
                    k++;
                }
                else{
                    // if not, do normal number change
                    nums[cur_target_pos] = nums[i];
                    cur_target_pos++;
                }
            }
            else{
                // if comes to a new number, do number change and chagne the record
                nums[cur_target_pos] = nums[i];
                cur_target_pos++;
                cur_num = nums[i];
                cur_n = 1;
            }
        }
        return n-k;
    }
};