#include <vector>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int count = 0;
        // mod_group[i] means the number of sum of subarrays that mod k = i
        vector<int> mod_group(k, 0);
        mod_group[0] = 1;  // empty
        int prefix_mod = 0;
        for(int num: nums){
            prefix_mod = (prefix_mod + num%k + k) % k;
            // add the current number of the same mod
            count += mod_group[prefix_mod];
            // add one the corresponding mod_group
            mod_group[prefix_mod]++;
        }
        return count;
    }
};