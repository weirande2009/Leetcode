#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.length();
        vector<int> last_pos(26, -1);
        for(int i=0; i<n; i++){
            last_pos[s[i]-'a'] = i;
        }
        // record current included char
        unordered_set<char> hashtable;
        // mono stack
        stack<char> st;
        for(int i=0; i<n; i++){
            // if already in stack, continue
            if(hashtable.find(s[i]) != hashtable.end()){
                continue;
            }
            // keep stack monotonic unless this is the last
            while(!st.empty() && st.top() > s[i] && last_pos[st.top()-'a'] > i){
                hashtable.erase(st.top());
                st.pop();
            }
            // push to stack
            st.push(s[i]);
            hashtable.insert(s[i]);
        }
        string ans;
        while(!st.empty()){
            ans += string(1, st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};