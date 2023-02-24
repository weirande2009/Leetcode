#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n = s.length();
        stack<pair<char, int>> st;
        for(int i=0; i<n; i++){
            if(st.empty()){
                st.push({s[i], 1});
            }
            else if(st.top().first == s[i]){
                if(st.top().second == k-1){
                    st.pop();
                }
                else{
                    pair<char, int> top = st.top();
                    st.pop();
                    top.second++;
                    st.push(top);
                }
            }
            else{
                st.push({s[i], 1});
            }
        }
        stack<char> rst;
        string ans;
        while(!st.empty()){
            for(int i=0; i<st.top().second; i++){
                rst.push(st.top().first);
            }
            st.pop();
        }
        while(!rst.empty()){
            ans.push_back(rst.top());
            rst.pop();
        }
        return ans;

    }
};