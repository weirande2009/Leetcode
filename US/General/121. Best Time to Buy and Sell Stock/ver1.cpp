#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int n = prices.size();
        int m = prices[n-1];
        for(int i=n-2; i>=0; i--){
            if(prices[i] < m){
                profit = max(profit, m-prices[i]);
            }
            else{
                m = prices[i];
            }
        }
        return profit;
    }
};