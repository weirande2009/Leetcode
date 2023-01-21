#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    void dfs(vector<unordered_set<int>>& adj, unordered_set<int>& visited, unordered_set<int>& route, int node, int parent, bool& ans){
        if(!ans){
            return;
        }
        route.insert(node);
        visited.erase(node);
        for(int child: adj[node]){
            if(child != parent){
                if(route.find(child) != route.end()){  // if find the same node, there is a circle
                    ans = false;
                    return;
                }
                dfs(adj, visited, route, child, node, ans);
                if(!ans){
                    return;
                }
            }
        }
        route.erase(node);
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>> adj(n); 
        unordered_set<int> visited;
        for(int i=0; i<n; i++){
            visited.insert(i);
        }
        for(auto& edge: edges){
            adj[edge[0]].insert(edge[1]);
            adj[edge[1]].insert(edge[0]);
        }
        unordered_set<int> route;
        bool ans = true;
        dfs(adj, visited, route, 0, -1, ans);
        return ans && visited.size() == 0;
    }
};