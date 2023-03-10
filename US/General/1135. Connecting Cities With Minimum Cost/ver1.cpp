#include <bits/stdc++.h>
using namespace std;

class DisjointSet{
private:
    vector<int> parents;  // the parent node of each node
    vector<int> weights;  // the number of node in the set for the root

public:
    DisjointSet(int n){
        parents.resize(n+1);
        weights.resize(n+1);
        for(int i=1; i<=n; i++){
            parents[i] = i;
        }
        for(int i=1; i<=n; i++){
            weights[i] = 1;
        }
    }

    void Union(int a, int b){
        int rootA = Find(a);
        int rootB = Find(b);
        // larger weight root as the root
        if(weights[rootA] > weights[rootB]){
            parents[rootB] = rootA;
            weights[rootA] += weights[rootB];
        }
        else{
            parents[rootA] = rootB;
            weights[rootB] += weights[rootA];
        }
    }

    // find the parent of a 
    int Find(int a){
        while(a != parents[a]){
            parents[a] = parents[parents[a]];  // directly set the grand parents to speed up
            a = parents[a];
        }
        return a;
    }

    bool isSameSet(int a, int b){
        return Find(a) == Find(b);
    }

};

class Solution {
public:
    int minimumCost(int n, vector<vector<int>>& connections) {
        DisjointSet* disjointSet = new DisjointSet(n);
        sort(connections.begin(), connections.end(), [](const vector<int>& v1, const vector<int>& v2){
            return v1[2] < v2[2];
        });
        // keep track of the total number of edges are used
        int total = 0;
        // keep track of the total cost
        int cost = 0;
        for(vector<int>& connection: connections){
            int a = connection[0];
            int b = connection[1];
            // if already in the set, continue
            if(disjointSet->isSameSet(a, b)){
                continue;
            }
            // union them
            disjointSet->Union(a, b);
            cost += connection[2];
            total++;
        }
        return total == n-1 ? cost : -1;
    }
};