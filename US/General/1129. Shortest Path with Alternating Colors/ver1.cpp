#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto& edge: redEdges){
            adj[edge[0]].push_back({edge[1], 0});
        }
        for(auto& edge: blueEdges){
            adj[edge[0]].push_back({edge[1], 1});
        }
        queue<pair<int, int>> q;
        vector<int> distance(n, -1);
        // seen[i][0] means the node i has seen the color 0 before to avoid loop
        vector<vector<bool>> seen(n, vector<bool>(2, false));
        distance[0] = 0;
        int step = 1;
        for(auto& p: adj[0]){
            q.push(p);
            distance[p.first] = distance[p.first] == -1 ? step : min(distance[p.first], step);
            seen[p.first][p.second] = true;
        }
        while(!q.empty()){
            queue<pair<int, int>> tmp_q;
            step++;
            while(!q.empty()){
                const auto& [node, color] = q.front();
                for(auto& p: adj[node]){
                    if(p.second != color && !seen[p.first][p.second]){
                        tmp_q.push(p);
                        distance[p.first] = distance[p.first] == -1 ? step : min(distance[p.first], step);
                        seen[p.first][p.second] = true;
                    }
                }
                q.pop();
            }
            q = tmp_q;
        }
        return distance;
    }
};