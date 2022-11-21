#include <vector>
using namespace std;



class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> record;
        int even = 0;
        int odd_pos = -1;
        // count the number of even number between every odd number
        for(int i=0; i<n; i++){
            if(nums[i] % 2){
                record.push_back(even);
                even = 0;
                odd_pos = i;
            }
            else{
                even++;
            }
        }
        int n_r = record.size();
        if(n_r < k){
            return 0;
        }
        int count = 0;
        // record the last part of even number
        record.push_back(n-odd_pos-1);
        for(int i=0; i<=n_r-k; i++){
            count += (record[i]+1) * (record[i+k]+1);
        }
        return count;
    }
};