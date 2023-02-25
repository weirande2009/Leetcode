#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reorganizeString(string s) {
        vector<pair<int, char>> countc(26);
        for(int i=0; i<26; i++){
            countc[i] = {0, 'a'+i};
        }
        for(char c: s){
            countc[c-'a'].first++;;
        }
        priority_queue<pair<int, char>> pq;
        for(int i=0; i<26; i++){
            if(countc[i].first > 0)
                pq.push(countc[i]);
        }
        int n = s.length();
        string ans;
        char last = 0;
        for(int i=0; i<n; i++){
            if(pq.top().second == last){
                auto t0 = pq.top();
                pq.pop();
                if(pq.empty()){
                    return "";
                }
                auto t1 = pq.top();
                pq.pop();
                ans += t1.second;
                last = t1.second;
                t1.first--;
                if(t1.first > 0){
                    pq.push(t1);
                }
                pq.push(t0);
            }
            else{
                auto t1 = pq.top();
                pq.pop();
                ans += t1.second;
                last = t1.second;
                t1.first--;
                if(t1.first > 0){
                    pq.push(t1);
                }
            }
        }
        return ans;
    }
};