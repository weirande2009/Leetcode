#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestFactorization(int num) {
        if(num == 1){
            return 1;
        }
        vector<int> factor_pool = {2, 3, 45, 7};
        string s;
        while(num > 1 && s.length() < 32){
            bool divided = false;
            for(int i=9; i>=2; i--){
                if(num % i == 0){
                    s = to_string(i) + s;
                    num /= i;
                    divided = true;
                    break;
                }
            }
            if(!divided){
                return 0;
            }
        }
        if(stoll(s) > INT_MAX){
            return 0;
        }
        return stoi(s);
    }
};