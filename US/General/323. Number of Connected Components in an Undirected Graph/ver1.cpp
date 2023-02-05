#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<bool> visited(n, false);
        vector<unordered_set<int>> adj(n);
        for(auto& edge: edges){
            adj[edge[0]].insert(edge[1]);
            adj[edge[1]].insert(edge[0]);
        }
        int count = 0;
        for(int i=0; i<n; i++){
            if(!visited[i]){
                queue<int> q;
                q.push(i);
                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    for(int e: adj[node]){
                        if(!visited[e]){
                            q.push(e);
                            visited[e] = true;
                        }
                    }
                }
                count++;
            }
        }
        return count;
    }
};