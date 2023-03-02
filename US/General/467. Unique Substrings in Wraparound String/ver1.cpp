#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findSubstringInWraproundString(string s) {
        int n = s.length();
        // key-last character, value-length
        char last = 0;
        int l = 0;
        vector<int> end_length(26, 0);
        int count = 0;
        for(int i=0; i<n; i++){
            if(last != 'a'+(s[i]-'a'+25)%26){
                l = 0;
            }
            end_length[s[i]-'a'] = max(end_length[s[i]-'a'], l+1);
            l++;
            last = s[i];
        }
        return accumulate(end_length.begin(), end_length.end(), 0);
    }
};