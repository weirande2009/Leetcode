#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:

    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int last = 0;
        // compute the case for arr0
        for(int i=0; i<n; i++){
            last += i*nums[i];
        }
        int m = last;
        // compute for other
        for(int i=1; i<n; i++){
            m = max(m, last-(sum-n*nums[i-1]));
            last = last-(sum-n*nums[i-1]);
        }
        return m;
    }
};