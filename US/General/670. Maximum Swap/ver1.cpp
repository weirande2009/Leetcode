#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.length();
        vector<int> max_e(n);
        int mx_pos = -1;
        for(int i=n-1; i>=0; i--){
            if(mx_pos == -1 || s[i] > s[mx_pos]){
                mx_pos = i;
            }
            max_e[i] = mx_pos;
        }
        // find the first element where the max element is not itself
        for(int i=0; i<n; i++){
            if(s[max_e[i]] > s[i]){
                char tmp = s[max_e[i]];
                s[max_e[i]] = s[i];
                s[i] = tmp;
                break;
            }
        }
        return stoi(s);
    }
};