// 解题思路
// 利用动态规划的方法，计算出1...n-1的最优解，从而推出n的最优解，且当n的时候，n-1之前的最优解已经得到

class Solution {
public:
    int cuttingRope(int n) {
        if(n <= 3){
            return n-1;
        }
        int* dp = new int[n];
        dp[0] = 1;
        dp[1] = 2;
        dp[2] = 3;
        for(int i=3; i<n; i++){
            int max_product = 0;
            for(int j=1; j<i; j++){
                if((i-j+1)*dp[j-1] > max_product){
                    max_product = (i-j+1)*dp[j-1];
                }
            }
            dp[i] = max_product;
        }
        int result = dp[n-1];
        delete[] dp;
        return result;
    }
};