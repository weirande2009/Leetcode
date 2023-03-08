#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isReachable(int targetX, int targetY) {
        int v = gcd(targetX, targetY);
        while (v % 2 == 0)
            v /= 2;
        return v == 1;
    }
};