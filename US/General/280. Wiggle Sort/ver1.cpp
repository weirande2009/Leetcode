#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int left = 1;
        int right = n-1;
        if(n % 2 == 0){
            right = n-2;
        }
        while(left < right){
            int tmp = nums[left];
            nums[left] = nums[right];
            nums[right] = tmp;
            left += 2;
            right -= 2;
        }
    }
};
