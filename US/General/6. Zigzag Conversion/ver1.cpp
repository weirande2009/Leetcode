#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1){
            return s;
        }
        string ans;
        // for the first row
        for(int i=0; i<s.length(); i+=numRows*2-2){
            ans += s[i];
        }
        // for the middle
        for(int i=1; i<numRows-1; i++){
            for(int j=i; j<s.length(); j+=numRows*2-2){
                ans += s[j];
                if(j+2*(numRows-i-1) < s.length()){
                    ans += s[j+2*(numRows-i-1)];
                }
            }
        }
        // for the last row
        for(int i=numRows-1; i<s.length(); i+=numRows*2-2){
            ans += s[i];
        }
        return ans;
    }
};