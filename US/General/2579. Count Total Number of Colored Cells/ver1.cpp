#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long coloredCells(int n) {
        long long count = 1;
        for(int i=2; i<=n; i++){
            count += (i-1) * 4;
        }
        return count;
    }
};
