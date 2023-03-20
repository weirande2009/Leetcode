#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int l = flowerbed.size();
        for(int i=0; i<l; i++){
            if(flowerbed[i]){
                continue;
            }
            bool ok = true;
            if(i > 0){
                if(flowerbed[i-1]){
                    ok = false;
                }
            }
            if(i < l-1){
                if(flowerbed[i+1]){
                    ok = false;
                }
            }
            if(ok){
                n--;
                flowerbed[i] = 1;
            }
        }
        return n <= 0;
    }
};