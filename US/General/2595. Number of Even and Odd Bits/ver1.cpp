#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> evenOddBit(int n) {
        int even = 0;
        int odd = 0;
        int i=0;
        while(n > 0){
            if(n % 2 == 1){
                if(i%2 == 1){
                    odd++;
                }
                else{
                    even++;
                }
            }
            i++;
            n /= 2;
        }
        return {even, odd};
    }
};