#include <vector>
using namespace std;



class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        // dp[i][j] means the length of the longest subarray that appears in nums1[i:n1] and nums2[j:n2]
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
        int m = 0;
        for(int i=n1-1; i>=0; i--){
            for(int j=n2-1; j>=0; j--){
                // if nums1[i] == nums2[j] compute the maximum length and record
                if(nums1[i] == nums2[j]){
                    dp[i][j] = 1 + dp[i+1][j+1];
                    m = max(m, dp[i][j]);
                }
                // if nums1[i] != nums2[j], just simply ignore, which means dp[i][j] = 0
            }
        }
        return m;
    }
};