#include <vector>
using namespace std;

class Solution {
public:
    long long minimumHealth(vector<int>& damage, int armor) {
        long long sum = 0;
        int m = 0;
        for(auto d: damage){
            m = max(m, d);
            sum += d;
        }
        if(armor <= m){
            sum -= armor;
        }
        else{
            sum -= m;
        }
        return sum+1;
    }
};
