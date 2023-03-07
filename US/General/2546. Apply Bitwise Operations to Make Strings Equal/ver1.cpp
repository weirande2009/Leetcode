#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool makeStringsEqual(string s, string target) {
        int n = s.length();
        bool s_all_zero = true;
        bool target_all_zero = true;
        for(int i=0; i<n; i++){
            if(s[i] == '1'){
                s_all_zero = false;
            }
            if(target[i] == '1'){
                target_all_zero = false;
            }
        }
        return !(s_all_zero^target_all_zero);
    }
};