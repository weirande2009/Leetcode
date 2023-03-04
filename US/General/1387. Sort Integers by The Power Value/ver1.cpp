#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dfs(unordered_map<int, int>& memo, int num){
        if(num == 1){
            return 0;
        }
        if(memo.find(num) != memo.end()){
            return memo[num];
        }
        int power;
        if(num % 2 == 0){
           power = 1 + dfs(memo, num/2);
        }
        else{
            power = 1 + dfs(memo, num*3+1);
        }
        memo[num] = power;
        return power;
    }

    int getKth(int lo, int hi, int k) {
        unordered_map<int, int> memo;
        for(int i=lo; i<=hi; i++){
            dfs(memo, i);
        }
        vector<pair<int, int>> powers(hi-lo+1);
        for(int i=lo; i<=hi; i++){
            powers[i-lo] = {memo[i], i};
        }
        sort(powers.begin(), powers.end());
        return powers[k-1].second;
    }
};