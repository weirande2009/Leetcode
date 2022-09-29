#include <vector>
using namespace std;

// Algorithm: O(n). Greedy. When the next price is higher than today, buy it. When the today's
// price is higher than hold stock price, sell it.

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profits = 0;
        int pre_price = 0;
        bool hold = false;
        for(int i=0; i<n; i++){
            if(hold){
                if(pre_price < prices[i]){
                    // Sell
                    profits += prices[i] - pre_price;
                    hold = false;
                }
            }
            if(!hold && i != n-1){
                if(prices[i] < prices[i+1]){
                    // Buy
                    hold = true;
                    pre_price = prices[i];
                }
            }
        }
        return profits;
    }
};