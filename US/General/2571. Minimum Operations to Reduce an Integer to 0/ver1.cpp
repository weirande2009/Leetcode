#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(int n) {
        int x = 1;
        if(n <= 1){
            return n;
        }
        while(x*2 < n){  // find the first power of 2 less than n
            x *= 2;
        }
        // the smaller one of 
        return min(minOperations(x*2-n), minOperations(n-x))+1;
    }
};