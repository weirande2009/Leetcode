#include <vector>
#include <numeric>
using namespace std;

// Algorithm: n(n+1)/2 = sum from 0 to n. Then subtract the sum of nums.

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int s = accumulate(nums.begin(), nums.end(), 0);
        return n*(n+1)/2-s;
    }
};