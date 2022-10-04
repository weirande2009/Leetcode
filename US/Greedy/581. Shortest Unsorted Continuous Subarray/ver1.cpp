#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

// Algorithm: O(n). Find the first i such that nums[i] < num[i+1] and find the smallest number k
// after i. Then from i to 0, find the first nums[j] < k, set left=j+1. Do the opposite from
// n-1 to 0 to find the first nums[i] > nums[i+1] to find the right border.

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int cur = -1;
        bool flag = false;
        int min_num = INT_MAX;
        for(int i=1; i<n; i++){
            if(!flag){
                if(nums[i] < nums[i-1]){
                    min_num = nums[i];
                    cur = i;
                    flag = true;
                }
            }
            else{
                if(nums[i] < min_num){
                    min_num = nums[i];
                    cur = i;
                }
            }
            
        }
        if(cur == -1){  // A sorted array
            return 0;
        }
        for(int i=cur-1; i>=0; i--){
            if(nums[i] <= min_num){
                left = i+1;
                break;
            }
        }
        int right = n;
        flag = false;
        int max_num = -INT_MAX;
        for(int i=n-2; i>=0; i--){
            if(!flag){
                if(nums[i] > nums[i+1]){
                    max_num = nums[i];
                    cur = i;
                    flag = true;
                }
            }
            else{
                if(nums[i] > max_num){
                    max_num = nums[i];
                    cur = i;
                }
            }
        }
        for(int i=cur+1; i<n; i++){
            if(nums[i] >= max_num){
                right = i;
                break;
            }
        }
        sort(nums.begin()+left, nums.begin()+right);
        return right-left;
    }
};