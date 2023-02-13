#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countOdds(int low, int high) {
        int count = (high - low) / 2;
        if(high%2 || low%2){
            count++;
        }
        return count;
    }
};