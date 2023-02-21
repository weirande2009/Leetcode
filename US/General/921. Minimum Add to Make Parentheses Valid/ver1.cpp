#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int count = 0;
        int n = s.length();
        for(int i=0; i<n; i++){
            if(s[i] == '('){
                st.push('(');
            }
            else{
                if(st.empty() || st.top() != '('){
                    count++;
                }
                else{
                    st.pop();
                }
            }
        }
        return count + st.size();
    }
};