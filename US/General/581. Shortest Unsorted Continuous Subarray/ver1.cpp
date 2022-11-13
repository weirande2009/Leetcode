#include <vector>
using namespace std;

// Algorithm: 
// Find left point:
// 1. find first nums[i-1] > nums[i]
// 2. find the smallest number after i
// 3. find the first number from i to 0 which is smaller than the smallesst number after i

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int left = -1;
        int right = -1;
        
        int n = nums.size();
        for(int i=1; i<n; i++){
            if(nums[i-1] > nums[i]){
                int m = nums[i];
                // find the smallest number after
                for(int j=i+1; j<n; j++){
                    m = min(m, nums[j]);
                }
                left = i-1;
                // find the first number before which is smaller than the smallest number after
                for(int j=i-2; j>=0; j--){
                    if(nums[j] <= m){
                        break;
                    }
                    left--;
                }
                break;
            }
        }
        if(left == -1){
            return 0;
        }
        for(int i=n-2; i>=0; i--){
            if(nums[i+1] < nums[i]){
                int m = nums[i];
                // find the largest number after
                for(int j=i-1; j>=0; j--){
                    m = max(m, nums[j]);
                }
                right = i+1;
                for(int j=i+2; j<n; j++){
                    if(nums[j] >= m){
                        break;
                    }
                    right++;
                }
                break;
            }
        }
        return right-left+1;
    }
};