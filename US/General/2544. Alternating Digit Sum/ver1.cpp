#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int alternateDigitSum(int n) {
        int sum = 0;
        string s = to_string(n);
        int sign = 1;
        for(char c: s){
            sum += sign * (c-'0');
            sign *= -1;
        }
        return sum;
    }
};