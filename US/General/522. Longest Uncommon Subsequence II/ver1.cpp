#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        unordered_map<string, int> hashtable;
        for(const string& str: strs){
            // there are totally (1 << str.length()) number of subsequence
            for(int i=0; i<(1 << str.length()); i++){
                string s = "";
                // check each bit in i, if bit[j] is 1, mean str[j] is in the subsequence
                for(int j=0; j<str.length(); j++){
                    if(((i >> j) & 1) == 1){ // if bit[j] is 1
                        s += str[j];
                    }
                }
                hashtable[s]++;
            }
        }
        int l = -1;
        // check the longest length of subsequence which appears only once
        for(auto& p: hashtable){
            if(p.second == 1){
                l = max(l, (int)p.first.length());
            }
        }
        return l;
    }
};