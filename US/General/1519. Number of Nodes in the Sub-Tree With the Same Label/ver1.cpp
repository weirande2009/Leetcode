#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> dfs(vector<vector<int>>& adj, int node, int parent, vector<int>& result, string& labels){
        int n = adj.size();
        vector<int> counts(26, 0);
        for(auto& child: adj[node]){
            if(child != parent){
                auto cts = dfs(adj, child, node, result, labels);
                for(int i=0; i<26; i++){
                    counts[i] += cts[i];
                }
            }
        }
        counts[labels[node]-'a']++;
        result[node] = counts[labels[node]-'a'];
        return counts;
    }


    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> adj(n);
        for(auto& edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int> result(n, 0);
        dfs(adj, 0, -1, result, labels);
        return result;
    }
};