#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& maze, const vector<int>& start, vector<int>& destination, unordered_set<int>& route, bool& found, int m, int n){
        if(found){
            return;
        }
        vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        route.insert(start[0]*n+start[1]);
        for(auto& direction: directions){
            int next_row = start[0]+direction[0];
            int next_col = start[1]+direction[1];
            if(next_row < 0 || next_row >= m || next_col < 0 || next_col >= n){
                continue;
            }
            if(maze[next_row][next_col] != 1){
                while(maze[next_row][next_col] != 1){
                    int new_row = next_row + direction[0];
                    int new_col = next_col + direction[1];
                    if(new_row < 0 || new_row >= m || new_col < 0 || new_col >= n || maze[new_row][new_col] == 1){
                        break;
                    }
                    next_row = new_row;
                    next_col = new_col;
                }
                if(next_row == destination[0] && next_col == destination[1]){
                    found = true;
                    return;
                }
                if(route.find(next_row*n+next_col) != route.end()){
                    continue;
                }
                dfs(maze, {next_row, next_col}, destination, route, found, m, n);
                if(found){
                    return;
                }
            }
        }
    }

    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        bool found = false;
        unordered_set<int> route;
        dfs(maze, start, destination, route, found, maze.size(), maze[0].size());
        return found;
    }
};