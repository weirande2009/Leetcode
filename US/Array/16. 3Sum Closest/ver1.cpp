#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;


// Algorithm: Almost the same as No.15. The only difference is that no matter whether closest
// answer is found, we need to update the left and right pointer according to the present difference
// between sum and target.


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int result = -100000;
        int dis = 100000;
        for(int i=0; i<n-1; i++){
            if(i > 0){
                if(nums[i] == nums[i-1]){
                    continue;
                }
            }
            int left_p = i+1;
            int right_p = n-1;
            while(left_p < right_p){
                int sum = nums[i] + nums[left_p] + nums[right_p];
                int pre_dis = abs(target - sum);
                if(pre_dis < dis){
                    result = sum;
                    dis = pre_dis;
                }
                if(target - sum > 0){
                    left_p++;
                }
                else{
                    right_p--;
                }
            }
        }
        return result;
    }
};


