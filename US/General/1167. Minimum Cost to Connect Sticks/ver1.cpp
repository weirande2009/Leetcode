#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        int n = sticks.size();
        priority_queue<int, vector<int>, greater<>> pq;
        for(int stick: sticks){
            pq.push(stick);
        }
        int cost = 0;
        while(pq.size() > 1){
            int stick1 = pq.top();
            pq.pop();
            int stick2 = pq.top();
            pq.pop();
            cost += stick1 + stick2;
            pq.push(stick1+stick2);
        }
        return cost;
    }
};