#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(const string& s){
        char mn = 'z';
        unordered_map<char, int> ht;
        for(char c: s){
            mn = min(c, mn);
            ht[c]++;
        }
        return ht[mn];
    }

    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> fw(words.size());
        for(int i=0; i<words.size(); i++){
            fw[i] = f(words[i]);
        }
        sort(fw.begin(), fw.end());

        vector<int> ans(queries.size());
        for(int i=0; i<queries.size(); i++){
            int fq = f(queries[i]);
            ans[i] = fw.end() - upper_bound(fw.begin(), fw.end(), fq);
        }
        return ans;
    }
};