#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(string& s, vector<string>& ans, int i, string& cur){
        int n = s.length();
        if(n == i){
            ans.push_back(cur);
            return;
        }
        if(s[i] >= '0' && s[i] <= '9'){
            cur.push_back(s[i]);
            dfs(s, ans, i+1, cur);
            cur.pop_back();
        }
        else if(s[i] >= 'a' && s[i] <= 'z'){
            cur.push_back(s[i]);
            dfs(s, ans, i+1, cur);
            cur.pop_back();
            
            cur.push_back(s[i]+'A'-'a');
            dfs(s, ans, i+1, cur);
            cur.pop_back();
        }
        else if(s[i] >= 'A' && s[i] <= 'Z'){
            cur.push_back(s[i]);
            dfs(s, ans, i+1, cur);
            cur.pop_back();
            
            cur.push_back(s[i]+'a'-'A');
            dfs(s, ans, i+1, cur);
            cur.pop_back();
        }
    }

    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        string cur;
        dfs(s, ans, 0, cur);
        return ans;
    }
};