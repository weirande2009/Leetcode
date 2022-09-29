#include <vector>
using namespace std;

// Algorithm: O(n). First loop which is from left to right to ensure that for each ratings[i],
// if ratings[i] > ratings[i-1], then nums[i] = nums[i-1]+1. The second loop which is from right
// to left to ensure that for each ratings[i], if ratings[i] > ratings[i+1], then 
// nums[i] = nums[i+1]+1 or nums[i], because nums[i] already has a value.

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> nums(n, 1);
        // From left to right
        for(int i=1; i<n; i++){
            if(ratings[i] > ratings[i-1]){
                nums[i] = nums[i-1]+1;
            }
        }
        for(int i=n-2; i>=0; i--){
            if(ratings[i] > ratings[i+1]){
                nums[i] = max(nums[i+1]+1, nums[i]);
            }
        }
        int total = 0;
        for(int i=0; i<n; i++){
            total += nums[i];
        }
        return total;
    }
};