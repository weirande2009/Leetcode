#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int n = position.size();
        int even = 0;
        int odd = 0;
        for(int p: position){
            if(p % 2 == 0){
                even++;
            }
            else{
                odd++;
            }
        }
        return min(odd, even);
    }
};