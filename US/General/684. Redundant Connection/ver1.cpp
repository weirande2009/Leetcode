#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    void dfs(vector<unordered_map<int, int>>& adj, int node, int parent, unordered_map<int, vector<int>>& route, bool& found, int& ans){
        if(found){
            return;
        }
        if(route.find(node) != route.end()){  // find a circle
            int start = route[node][3];
            int idx = -1;
            for(auto& p: route){
                if(p.second[0] > idx && p.second[3] >= start){
                    idx = p.second[0];
                }
            }
            ans = idx;
            found = true;
            return;
        }
        for(auto& p: adj[node]){
            if(p.first != parent){
                route[node] = {p.second, node, p.first, (int)route.size()};
                dfs(adj, p.first, node, route, found, ans);
                if(found){
                    return;
                }
                route.erase(node);
            }
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<unordered_map<int, int>> adj(n);
        for(int i=0; i<n; i++){
            adj[edges[i][0]-1][edges[i][1]-1] = i;
            adj[edges[i][1]-1][edges[i][0]-1] = i;
        }
        unordered_map<int, vector<int>> route;
        bool found = false;
        int ans;
        dfs(adj, 0, -1, route, found, ans);
        return edges[ans];
    }
};