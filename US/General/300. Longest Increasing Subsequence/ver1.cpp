#include <vector>
using namespace std;

// Algorithm: record[i] means the number of nums[j](j<i) such that nums[j] < nums[i]

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> record(n, 0);
        int m = 0;
        for(int i=1; i<n; i++){
            // find first nums[j] < nums[i]
            for(int j=i-1; j>=0; j--){
                if(nums[j] < nums[i]){
                    record[i] = max(record[i], record[j] + 1);
                }
            }
            m = max(m, record[i]);
        }
        return m+1;
    }
};