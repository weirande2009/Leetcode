#include <vector>
using namespace std;

class Solution {
public:
    int dfs(vector<int>& nums, int left, int right, int turn){
        if(left == right){
            return turn*nums[left];
        }
        // nums[left] is the score we get this turn, dfs() is the score the opponent gets
        int start = nums[left]-dfs(nums, left+1, right, -turn);
        int end = nums[right]-dfs(nums, left, right-1, -turn);
        // return the higher one
        return max(start, end);
    }


    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        return dfs(nums, 0, n-1, 1) >= 0;
    }
};