#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(vector<unordered_set<int>>& adj, vector<bool>& visited, int node, int parent, long long& count){
        visited[node] = true;
        count++;
        for(int child: adj[node]){
            if(child != parent && !visited[child]){
                dfs(adj, visited, child, node, count);
            }
        }
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>> adj(n);
        for(const vector<int>& edge: edges){
            adj[edge[0]].insert(edge[1]);
            adj[edge[1]].insert(edge[0]);
        }
        vector<bool> visited(n, false);
        long long group_count = 0;
        long long ans = 0;
        for(int i=0; i<n; i++){
            if(!visited[i]){
                long long count = 0;
                dfs(adj, visited, i, -1, count);
                ans += count * group_count;
                group_count += count;
            }
        }
        return ans;
    }
};