#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1){
            return {0};
        }
        else if(n == 2){
            return {0, 1};
        }
        vector<unordered_set<int>> adj(n);
        for(auto& edge: edges){
            adj[edge[0]].insert(edge[1]);
            adj[edge[1]].insert(edge[0]);
        }
        vector<int> v;
        for(int i=0; i<n; i++){
            if(adj[i].size() == 1){
                v.push_back(i);
            }
        }
        int left = n;
        // in each iteration, we delete the leaves and add the new leaves to the vector until there no more than 2 leaves
        // which is the answer
        while(left > 2){
            left -= v.size();
            vector<int> tmp_v;
            for(int leaf: v){
                int neighbor = *(adj[leaf].begin());
                adj[neighbor].erase(leaf);
                if(adj[neighbor].size() == 1){
                    tmp_v.push_back(neighbor);
                }
            }
            v = tmp_v;
        }
        return v;
    }
};