#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<unordered_map<int, int>> adj(n+1);
        for(const vector<int>& road: roads){
            adj[road[0]][road[1]] = road[2];
            adj[road[1]][road[0]] = road[2];
        }
        vector<int> min_score(n+1, INT_MAX);
        // pair: {city, score}
        queue<pair<int, int>> q;
        q.push({1, INT_MAX});
        int ans = INT_MAX;
        while(!q.empty()){
            pair<int, int> p = q.front();
            if(p.first == n){
                ans = min(ans, p.second);
            }
            q.pop();
            for(auto [child, score]: adj[p.first]){
                score = min(p.second, score);
                if(min_score[child] > score){
                    min_score[child] = score;
                    q.push({child, score});
                }
            }
        }
        return ans;
    }
};