#include <vector>
#include <cmath>
using namespace std;

// Algorithm: Since we cannot do two transactions in one time, the two transactions are
// separated. So we compute the max profit from left to right and from right to left and
// record them in left_profits and right_profits. left_profits[i] means the max profit
// from 0 to i. right_profits[i] means the max profit from i to n-1.
// So left_profits[i] + right_profits[i+1] means the the max profit of the two subarrays
// one from 0 to i, and the other from i+1 to n-1. So we only need to compare all the sum
// of these, we can find the answer. And left_profits[n-1] means only one transaction,
// as well as right_profits[0]


class Solution {
public:
    int maxPro(vector<int>& prices, int start, int end) {
        int profit = 0;
        int n = prices.size();
        int m = prices[end];
        for(int i=end-1; i>=start; i--){
            if(prices[i] < m){
                profit = max(profit, m-prices[i]);
            }
            else{
                m = prices[i];
            }
        }
        return profit;
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> left_profits(n, 0);
        vector<int> right_profits(n, 0);
        // left to right
        int profit = 0;
        int m = prices[0];
        for(int i=0; i<n; i++){
            profit = max(profit, prices[i]-m);
            left_profits[i] = profit;
            m = min(m, prices[i]);
        }
        // right to left
        m = prices[n-1];
        profit = 0;
        for(int i=n-1; i>=0; i--){
            profit = max(profit, m-prices[i]);
            right_profits[i] = profit;
            m = max(m, prices[i]);
        }
        profit = 0;
        for(int i=0; i<n-1; i++){
            profit = max(profit, left_profits[i]+right_profits[i+1]);
        }
        
        return max(profit, max(left_profits[n-1], right_profits[0]));
    }
};