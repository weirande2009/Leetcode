#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.length() + 1;
        vector<int> ans(n, 0);
        int i = 0;
        int d = n-1;
        if(s[0] == 'I'){
            ans[0] = i++;
        }
        else{
            ans[0] = d--;
        }
        for(int j=1; j<n-1; j++){
            if(s[j] == 'D'){
                ans[j] = d--;
            }
            else{
                ans[j] = i++;
            }
        }
        ans[n-1] = d;
        return ans;
    }
};