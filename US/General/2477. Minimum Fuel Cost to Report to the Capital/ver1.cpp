#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    pair<long long, int> dfs(vector<unordered_set<int>>& adj, int node, int parent, int seats){
        long long fuel = 0;
        int people = 1;
        for(int child: adj[node]){
            if(child != parent){
                auto son = dfs(adj, child, node, seats);
                fuel += son.first;
                people += son.second;
            }
        }
        int car_num = ceil((double)people / seats);
        if(parent == -1){
            return {fuel, people};
        }
        return {fuel+car_num, people};
    }

    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size()+1;
        vector<unordered_set<int>> adj(n);
        for(auto& road: roads){
            adj[road[0]].insert(road[1]);
            adj[road[1]].insert(road[0]);
        }
        auto [fuel, people] = dfs(adj, 0, -1, seats);
        return fuel;
    }
};