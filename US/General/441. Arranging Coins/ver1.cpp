#include <cmath>
using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
        int k = (-1+sqrt(1+8*(double)n)) / 2;
        if(round(k)-k < 1e-6){
            return round(k);
        }
        else{
            return round(k)-1;
        }
    }
};