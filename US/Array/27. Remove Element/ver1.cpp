#include <vector>
using namespace std;

// Algorithm: O(n), use two pointers, one to present the current index of array and 
// the other one to present the current index that without 'val'.


class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int j = 0;
        for(int i=0; i<n; i++){
            if(nums[i] != val){
                nums[j] = nums[i];
                j++;
            }
        }
        return j;
    }
};


