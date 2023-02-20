#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> split(const string& s, const string& sep){
        vector<int> ans;
        int begin = 0;
        while(1){
            int pos = s.find(sep, begin);
            if(pos == s.npos){
                break;
            }
            if(s.substr(begin, pos-begin) == "#"){
                ans.push_back(-1);
            }
            else{
                ans.push_back(stoi(s.substr(begin, pos-begin)));
            }
            begin = pos+1;
        }
        ans.push_back(-1);
        return ans;
    }

    void dfs(const vector<int>& preorder, int& i, bool& ok){
        if(!ok){
            return;
        }
        if(i >= preorder.size()){
            ok = false;
            return;
        }
        if(preorder[i++] == -1){
            return;
        }
        dfs(preorder, i, ok);
        dfs(preorder, i, ok);
    }

    bool isValidSerialization(string preorder) {
        if(preorder[preorder.size()-1] != '#'){
            return false;
        }
        vector<int> v = split(preorder, ",");
        bool ok = true;
        int i=0;
        dfs(v, i, ok);
        return ok && i == v.size();
    }
};