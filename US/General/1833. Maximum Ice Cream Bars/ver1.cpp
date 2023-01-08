#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n = costs.size();
        // sort
        sort(costs.begin(), costs.end());
        // greedy
        for(int i=0; i<n; i++){
            coins -= costs[i];
            if(coins < 0){
                return i;
            }
        }
        return n;
    }
};