#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(vector<unordered_map<int, int>>& adj, int node, int parent, int& count){
        for(const auto& [child, direction]: adj[node]){
            if(child != parent){
                if(direction == 1){
                    count++;
                }
                dfs(adj, child, node, count);
            }
        }

    }

    int minReorder(int n, vector<vector<int>>& connections) {
        vector<unordered_map<int, int>> adj(n);
        for(const vector<int>& connection: connections){
            adj[connection[0]][connection[1]] = 1;
            adj[connection[1]][connection[0]] = -1;
        }
        int count = 0;
        dfs(adj, 0, -1, count);
        return count;
    }
};