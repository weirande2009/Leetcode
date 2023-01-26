#include <vector>
#include <queue>
#include <limits.h>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<unordered_map<int, int>> adj(n);
        for(auto& flight: flights){
            adj[flight[0]][flight[1]] = flight[2];
        }
        queue<pair<int, int>> q;
        q.push({src, 0});
        vector<int> dis(n, INT_MAX);
        while(k >= 0){
            queue<pair<int, int>> tmp_q;
            while(!q.empty()){
                auto [node, price] = q.front();
                q.pop();
                for(auto& p: adj[node]){
                    if(price+p.second >= dis[p.first]){
                        continue;
                    }
                    dis[p.first] = price+p.second;
                    tmp_q.push({p.first, p.second+price});
                }
            }
            q = tmp_q;
            k--;
        }
        return dis[dst] == INT_MAX ? -1 : dis[dst];
    }
};