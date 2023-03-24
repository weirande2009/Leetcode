#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(vector<unordered_set<int>>& adj, unordered_set<int>& group, vector<bool>& visited, int node, int parent){
        if(group.find(node) != group.end()){
            return;
        }
        group.insert(node);
        visited[node] = true;
        for(int child: adj[node]){
            if(child != parent){
                dfs(adj, group, visited, child, node);
            }
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<unordered_set<int>> adj(n);
        for(const vector<int>& connection: connections){
            adj[connection[0]].insert(connection[1]);
            adj[connection[1]].insert(connection[0]);
        }
        int group_num = 0;
        vector<bool> visited(n, false);
        int extra_connection = 0;
        for(int i=0; i<n; i++){
            if(!visited[i]){
                int count = 0;
                unordered_set<int> group;
                dfs(adj, group, visited, i, -1);
                for(int node: group){
                    count += adj[node].size();
                }
                count /= 2;
                extra_connection += count - (group.size() - 1);
                group_num++;
            }
        }
        for(int i=0; i<n; i++){
            if(!visited[i]){
                group_num++;
            }
        }
        return group_num-1 <= extra_connection ? group_num-1 : -1;
    }
};