#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n = trips.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        for(int i=0; i<n; i++){
            pq.push({trips[i][1], trips[i][0]});
            pq.push({trips[i][2], -trips[i][0]});
        }
        int count = 0;
        while(!pq.empty()){
            int pos = pq.top().first;
            while(!pq.empty() && pq.top().first == pos){
                count += pq.top().second;
                pq.pop();
            }
            if(count > capacity){
                return false;
            }
        }
        return true;
    }
};