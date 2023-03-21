#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSplits(string s) {
        int n = s.length();
        unordered_set<char> hashtable;
        vector<int> left(n);
        for(int i=0; i<n; i++){
            hashtable.insert(s[i]);
            left[i] = hashtable.size();
        }
        hashtable.clear();
        vector<int> right(n);
        for(int i=n-1; i>=0; i--){
            hashtable.insert(s[i]);
            right[i] = hashtable.size();
        }
        int ans = 0;
        for(int i=0; i<n-1; i++){
            if(left[i] == right[i+1]){
                ans++;
            }
        }
        return ans;
    }
};