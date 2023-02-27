#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> hashtable;
        for(const string& word: words){
            hashtable[word]++;
        }
        auto comparator = [](const pair<string, int>& p1, const pair<string, int>& p2){
            if(p1.second == p2.second){
                return p1.first > p2.first;
            }
            else{
                return p1.second < p2.second;
            }
        };
        priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(comparator)> pq(comparator);
        for(const auto& p: hashtable){
            pq.push(p);
        }
        vector<string> ans;
        while(k > 0){
            ans.push_back(pq.top().first);
            pq.pop();
            k--;
        }
        return ans;
    }
};