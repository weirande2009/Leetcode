#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        if(n == 1){
            return 0;
        }
        // the pair is the node and the bit mask
        queue<pair<int, int>> q;
        // when the mask equals to the ending mask, over
        int ending_mask = (1 << n) - 1;
        // seen[i][j] means in the node i, it has seen the bitmask before
        vector<vector<bool>> seen(n, vector<bool>(ending_mask, false));
        int step = 0;
        // initialize the q and seen as all possible start
        for(int i=0; i<graph.size(); i++){
            seen[i][1 << i] = true;
            q.push({i, 1 << i});
        }
        // bfs all together
        while(!q.empty()){
            queue<pair<int, int>> tmp_q;
            while(!q.empty()){
                auto& [node, bitmask] = q.front();
                for(int child: graph[node]){
                    int new_bitmask = bitmask | (1 << node);
                    if(new_bitmask == ending_mask){
                        return step;
                    }
                    if(!seen[child][new_bitmask]){
                        tmp_q.push({child, new_bitmask});
                        seen[child][new_bitmask] = true;
                    }
                }
                q.pop();
            }
            q = tmp_q;
            step++;
        }
        return -1;
    }
};