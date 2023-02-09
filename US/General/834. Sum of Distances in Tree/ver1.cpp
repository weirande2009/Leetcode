#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // compute the answer for the root node and compute the number of nodes in each subtree
    void dfs(vector<unordered_set<int>>& adj, vector<int>& ans, vector<int>& count, int node, int parent){
        for(int child: adj[node]){
            if(child != parent){
                dfs(adj, ans, count, child, node);
                // update count
                count[node] += count[child];
                // update length
                ans[node] += ans[child] + count[child];
            }
        }
    }

    // compute the answer for every node according to the root's answer
    void dfs2(vector<unordered_set<int>>& adj, vector<int>& ans, vector<int>& count, int node, int parent, int n){
        for(int child: adj[node]){
            if(child != parent){
                ans[child] = ans[node] - count[child] + n - count[child];
                dfs2(adj, ans, count, child, node, n);
            }
            
        }
    }


    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>> adj(n);
        for(auto& edge: edges){
            adj[edge[0]].insert(edge[1]);
            adj[edge[1]].insert(edge[0]);
        }
        vector<int> ans(n);
        vector<int> count(n, 1);
        dfs(adj, ans, count, 0, -1);
        dfs2(adj, ans, count, 0, -1, n);
        return ans;
    }
};