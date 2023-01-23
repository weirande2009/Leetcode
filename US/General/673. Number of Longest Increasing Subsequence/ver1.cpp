#include <vector>
using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        // lens[i] means the length of the longest subsequences ending with i
        vector<int> lens(n, 0);
        // counts[i] means the number of length of the longest subsequences ending with i
        vector<int> counts(n, 0);
        int mx = 0;
        int count = 0;
        for(int i=0; i<n; i++){
            lens[i] = 1;
            counts[i] = 1;
            for(int j=0; j<i; j++){
                if(nums[i] > nums[j]){
                    if(lens[i] < lens[j]+1){  // including the nums[i]
                        lens[i] = lens[j]+1;
                        counts[i] = counts[j];
                    }
                    else if(lens[i] == lens[j]+1){
                        counts[i] += counts[j];
                    }
                }
            }
            if(lens[i] == mx){
                count += counts[i];
            }
            else if(lens[i] > mx){
                mx = lens[i];
                count = counts[i];
            }
        }
        return count;
    }
};