#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<unordered_map<int, int>> adj(n);
        for(auto& edge: edges){
            adj[edge[0]][edge[1]] = edge[2];
            adj[edge[1]][edge[0]] = edge[2];
        }
        int mn = INT_MAX;
        int city = -1;
        for(int i=0; i<n; i++){
            int count = 0;
            vector<int> dis(n, INT_MAX);
            dis[i] = 0;
            queue<int> q;
            q.push(i);
            while(!q.empty()){
                int c = q.front();
                for(auto p: adj[c]){
                    if(dis[p.first] > dis[c] + p.second){
                        dis[p.first] = dis[c] + p.second;
                        q.push(p.first);
                    }
                }
                q.pop();
            }
            for(int j=0; j<n; j++){
                if(i != j && dis[j] <= distanceThreshold){
                    count++;
                }
            }
            if(count <= mn){
                mn = count;
                city = i;
            }
        }
        return city;
    }
};