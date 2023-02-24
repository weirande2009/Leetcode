#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.length();
        stack<char> st;
        for(int i=0; i<n; i++){
            if(st.empty() || st.top() != s[i]){
                st.push(s[i]);
            }
            else{
                st.pop();
            }
        }
        stack<char> rst;
        string ans;
        while(!st.empty()){
            rst.push(st.top());
            st.pop();
        }
        while(!rst.empty()){
            ans.push_back(rst.top());
            rst.pop();
        }
        return ans;
    }
};