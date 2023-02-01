#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findNthDigit(int n) {
        // the total number of digit in length of i is 9*i*10^(i-1)
        int length = 1;
        for(int i=1; i<100; i++){
            long long num = 9*i*pow(10, i-1);
            if(num >= n){
                length = i;
                break;
            }
            n -= num;
        }
        n -= +1;
        int index = n / length;
        int num = pow(10, length-1) + index;
        n %= length;
        return to_string(num)[n]-'0';
    }
};