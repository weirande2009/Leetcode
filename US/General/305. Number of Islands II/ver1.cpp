#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        // 0-water, >0-island no.
        vector<vector<int>> grids(m, vector<int>(n, 0));
        // record the current island no.
        int island_no = 1;
        // record the island of the no.(key)
        unordered_map<int, vector<pair<int, int>>> hashtables;
        vector<int> ans;
        int count = 0;
        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for(auto& position: positions){
            if(grids[position[0]][position[1]] != 0){
                ans.push_back(count);
                continue;
            }
            count++;
            unordered_set<int> adj_island_no;
            for(int i=0; i<4; i++){
                int row = position[0] + directions[i][0];
                int col = position[1] + directions[i][1];
                if(row < 0 || row >= m || col < 0 || col >= n || grids[row][col] == 0){
                    continue;
                }
                adj_island_no.insert(grids[row][col]);
            }
            // for each different island, merge them
            vector<pair<int, int>> new_island = {{position[0], position[1]}};
            for(int ino: adj_island_no){
                // add all old island to new
                new_island.insert(new_island.end(), hashtables[ino].begin(), hashtables[ino].end());
                // delele old island
                hashtables.erase(ino);
            }
            // add the new formed island to hashtable
            hashtables[island_no] = new_island;
            // set the island no to grids
            for(auto& p: new_island){
                grids[p.first][p.second] = island_no;
            }
            island_no++;
            count -= adj_island_no.size();
            ans.push_back(count);
        }
        return ans;
    }
};