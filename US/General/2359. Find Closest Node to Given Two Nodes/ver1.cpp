#include <vector>
#include <unordered_set>
#include <limits.h>
using namespace std;

class Solution {
public:
    void dfs(vector<int>& edges, unordered_set<int>& route, vector<int>& dis, int node, int step){
        if(route.find(node) != route.end()){
            dis[node] = min(dis[node], step);
            return;
        }
        else{
            route.insert(node);
            dis[node] = step;
        }
        if(edges[node] != -1){
            dfs(edges, route, dis, edges[node], step+1);
        }
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> node1_dis(n, INT_MAX);
        vector<int> node2_dis(n, INT_MAX);
        unordered_set<int> route;
        // find the distance from node1 to all other nodes
        dfs(edges, route, node1_dis, node1, 0);
        route.clear();
        // find the distance from node2 to all other nodes
        dfs(edges, route, node2_dis, node2, 0);
        int node = -1;
        int mn = INT_MAX;
        for(int i=0; i<n; i++){
            if(mn > max(node1_dis[i], node2_dis[i])){
                mn = max(node1_dis[i], node2_dis[i]);
                node = i;
            }
        }
        return node;
    }
};