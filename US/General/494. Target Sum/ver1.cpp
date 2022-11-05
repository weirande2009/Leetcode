#include <vector>
using namespace std;


class Solution {
public:
    void dfs(vector<int>& nums, int& count, int sum, int layer, int target){
        if(layer == nums.size()){
            if(sum == target){
                count++;
            }
            return;
        }
        dfs(nums, count, sum+nums[layer], layer+1, target);
        dfs(nums, count, sum-nums[layer], layer+1, target);
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int count = 0;
        dfs(nums, count, 0, 0, target);
        return count;
    }
};