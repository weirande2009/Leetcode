#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int, int> wallet;
        wallet[20] = 0;
        wallet[10] = 0;
        wallet[5] = 0;
        for(int bill: bills){
            int change = bill - 5;
            wallet[bill]++;
            if(change != 0){
                // 10
                bool ok = false;
                if(change >= 10){
                    if(wallet[10] > 0){
                        wallet[10]--;
                        change -= 10;
                        if(change == 0){
                            ok = true;
                        }
                    }
                }
                // 5
                if(wallet[5]*5 >= change && !ok){
                    wallet[5] -= change/5;
                    ok = true;
                }
                if(!ok){
                    return false;
                }
            }
        }
        return true;
    }
};