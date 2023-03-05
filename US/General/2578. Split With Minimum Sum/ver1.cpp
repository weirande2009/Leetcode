#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int splitNum(int num) {
        string s = to_string(num);
        sort(s.begin(), s.end());
        string s1, s2;
        int i=0;
        while(i < s.length()){
            s1 += s[i++];
            if(i >= s.length()){
                break;
            }
            s2 += s[i++];
        }
        return stoi(s1) + stoi(s2);
        
    }
};