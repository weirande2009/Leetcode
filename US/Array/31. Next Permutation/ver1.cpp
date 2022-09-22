#include <vector>
#include <algorithm>
using namespace std;

// Algorithm: First, from back to front, find the first nums[i] which nums[i] > nums[i-1].
// Then, find largest k that k > i and nums[k] > nums[i-1]. Swap nums[k] and nums[i-1].
// Finally, sort nums[i:].

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        // Find the first back > front
        int next_begin = 0;
        for(int i=n-1; i>=1; i--){
            if(nums[i] > nums[i-1]){
                int k = i;
                for(int j=i; j<n; j++){
                    if(nums[j] > nums[i-1]){
                        k = j;
                    }
                }
                int tmp = nums[i-1];
                nums[i-1] = nums[k];
                nums[k] = tmp;
                next_begin = i;
                break;
            }
        }
        sort(nums.begin()+next_begin, nums.end());
    }
};


