#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int seen_once = 0;
        int seen_twice = 0;
        for(int num: nums){
            // in bit wise, if seen_twice is 0, then it's the first time or third time we see this bit, record it
            seen_once = ~seen_twice & (seen_once^num);
            // in bit wise, if seen_once is 0, then it's the second time we see this bit, record it
            seen_twice = ~seen_once & (seen_twice^num);
        }
        return seen_once;
    }
};