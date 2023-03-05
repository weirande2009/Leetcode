#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int passThePillow(int n, int time) {
        int p = time % (2*(n-1));
        if(p < n){
            return p+1;
        }
        else{
            return 2*n-p-1;
        }
    }
};