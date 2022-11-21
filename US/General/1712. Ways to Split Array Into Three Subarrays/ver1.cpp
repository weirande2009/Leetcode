#include <vector>
using namespace std;


class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        int n = nums.size();
        vector<int> sum(n, 0);
        sum[0] = nums[0];
        for(int i=1; i<n; i++){
            sum[i] = sum[i-1] + nums[i];
        }
        int count = 0;
        int MOD = 1000000007;
        // i means the last end pointer for the first array
        // j means the first valid begin pointer for the second array
        // k means the last valid end pointer for the second array
        for(int i=0, j=0, k=0; i<n; i++){
            j = max(j, i+1);
            // look for j
            while(j < n-1 && sum[j] < 2*sum[i]){
                j++;
            }
            // now find j and continue to find k
            k = max(j, k);  // k should be at least at j
            while(k < n-1 && sum[k] - sum[i] <= sum[n-1] - sum[k]){
                k++;
            }
            count = (count+k-j) % MOD;
        }
        return count;
    }
};