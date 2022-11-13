#include <vector>
using namespace std;

// Same number will disappear with an NOR operation

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int r = 0;
        for(int i: nums){
            r ^= i;
        }
        return r;
    }
};