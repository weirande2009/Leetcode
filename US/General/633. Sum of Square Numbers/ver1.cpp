#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        if(c <= 2){
            return true;
        }
        for(int i=1; i<=c; i++){
            long long bsqr = c-(long long)i*i;
            if(bsqr < 0){
                return false;
            }
            long long bsqrt = sqrt(bsqr);
            if(bsqrt*bsqrt == bsqr){
                return true;
            }
        }
        return false;
    }
};