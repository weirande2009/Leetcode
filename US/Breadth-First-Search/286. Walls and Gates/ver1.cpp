#include <vector>
#include <unordered_set>
using namespace std;

// Algorithm: BFS. from every gate, bfs and count the steps. Restrict when the next room's
// layer is already smaller.

class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        unordered_set<int> gates;
        int n = rooms.size();
        int m = rooms[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(rooms[i][j] == 0){
                    gates.insert(i*m+j);
                }
            }
        }
        for(auto gate: gates){
            unordered_set<int> q;
            q.insert(gate);
            int layer = 0;
            while(!q.empty()){
                unordered_set<int> new_q;
                for(auto pos: q){
                    int x = pos / m;
                    int y = pos % m;
                    if(rooms[x][y] > layer)
                        rooms[x][y] = layer;
                    if(x > 0){
                        if(rooms[x-1][y] != -1 && rooms[x-1][y] > layer+1){
                            new_q.insert((x-1)*m+y);
                        }
                    }
                    if(x < n-1){
                        if(rooms[x+1][y] != -1 && rooms[x+1][y] > layer+1){
                            new_q.insert((x+1)*m+y);
                        }
                    }
                    if(y > 0){
                        if(rooms[x][y-1] != -1 && rooms[x][y-1] > layer+1){
                            new_q.insert(x*m+y-1);
                        }
                    }
                    if(y < m-1){
                        if(rooms[x][y+1] != -1 && rooms[x][y+1] > layer+1){
                            new_q.insert(x*m+y+1);
                        }
                    }
                }
                q = new_q;
                layer++;
            }
        }
    }
};