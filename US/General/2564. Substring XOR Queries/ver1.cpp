#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
        vector<vector<int>> ans;
        int n = s.length();
        // key is number, value is a pair of begin and end
        unordered_map<int, pair<int, int>> hashtable;
        // build hashtable for all possible substrings
        for(int i=0; i<n; i++){
            if(s[i] == '0'){
                if(!hashtable.count(0)){
                    hashtable[0] = {i, i};
                }
                continue;
            }
            int decimal = 0;
            for(int j=i; j<min(i+32, n); j++){
                decimal = (decimal << 1) + s[j]-'0';
                if(!hashtable.count(decimal)){
                    hashtable[decimal] = {i, j};
                }
            }
        } 
        for(auto& query: queries){
            int target = query[0]^query[1];
            if(hashtable.count(target)){
                ans.push_back({hashtable[target].first, hashtable[target].second});
            }
            else{
                ans.push_back({-1, -1});
            }
        }
        return ans;
    }
};