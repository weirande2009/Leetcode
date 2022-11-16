#include <vector>
#include <cmath>
#include <limits.h>
using namespace std;

// Algorithm: Use state machine, there are three states: held, sold and reset, and we have
// three actions: sell, buy and do nothing.

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int sold = INT_MIN;
        int held = INT_MIN;
        int reset = 0;
        
        for(int price: prices){
            int pre_sold = sold;
            
            sold = held + price;
            held = max(held, reset-price);
            reset = max(reset, pre_sold);
        }
        
        return max(sold, reset);
    }
};