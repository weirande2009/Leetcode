#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int, int>> capital_profits;
        for(int i=0; i<n; i++){
            capital_profits.push_back({capital[i], profits[i]});
        }
        sort(capital_profits.begin(), capital_profits.end());
        int idx = 0;
        // store the profit so far
        priority_queue<int> pq;
        for(int i=0; i<k; i++){
            // push all capital less than current w
            while(idx < n && capital_profits[idx].first <= w){
                pq.push(capital_profits[idx++].second);
            }
            // greedy, find the highest profit so far
            if(pq.empty()){
                break;
            }
            w += pq.top();
            pq.pop();
        }
        return w;
    }
};