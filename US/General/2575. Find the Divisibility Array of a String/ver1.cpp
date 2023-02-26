#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        int n = word.length();
        vector<int> ans(n, 0);
        long long sum = 0;
        for(int i=0; i<n; i++){
            sum = ((sum * (10 % m)) % m + (word[i]-'0') % m) % m;
            ans[i] = sum == 0;
        }
        return ans;
    }
};