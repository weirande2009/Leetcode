#include <vector>
using namespace std;

// Algorithm: O(n), use two pointer for the array, one to show the present index,
// and the other to show the present non-duplicate index of array.

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int d = 1;
        int j = 0;
        for(int i=1; i<n; i++){
            if(nums[i] != nums[j]){
                j++;
                nums[j] = nums[i];
                d++;
            }
        }
        return d;
    }
};





