#include <bits/stdc++.h>
using namespace std;

class MyComparator{
public:
    constexpr bool operator()(
        const pair<char, int>& a,
        const pair<char, int>& b)
        const noexcept
    {
        return a.second < b.second;
    }
};

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> frequencies;
        for(char c: s){
            frequencies[c]++;
        }
        priority_queue<pair<char, int>, vector<pair<char, int>>, MyComparator> pq;
        for(const pair<char, int>& p: frequencies){
            pq.push(p);
        }
        string ans;
        while(!pq.empty()){
            for(int i=0; i<pq.top().second; i++){
                ans += string(1, pq.top().first);
            }
            pq.pop();
        }
        return ans;
    }
};