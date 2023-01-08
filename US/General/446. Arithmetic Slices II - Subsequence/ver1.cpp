#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:


    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        // dp[i][j] means the length of subsequence with end in i and distance in j
        vector<unordered_map<long long, int>> dp(n);
        int ans = 0;
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                long long dis = (long long)nums[i]-(long long)nums[j];
                int sum = 0;
                if(dp[j].find(dis) != dp[j].end()){
                    sum = dp[j][dis];
                }
                // store a weak arithmatic. In the future, if there is another the same dis, we can use the 1 as the sum
                dp[i][dis] += sum + 1;
                ans += sum;
            }
        }
        return ans;
    }
};