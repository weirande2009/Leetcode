#include <unordered_set>
#include <vector>
using namespace std;

// Algorithm: Use a set to record the position of all island. Get an island i from set, DFS from 
// i, up, down, right, left recursively. Return if current grid is '0'. if '1', set grid '0' to 
// denote that this grid is visited and erase this grid from set. Do the above recursion until
// the set is empty. Every time we get a beginning island from set, the count++.

class Solution {
public:
    void Recursion(vector<vector<char>>& grid, unordered_set<int>& islands, int x, int y, int n, int m){
        if(grid[x][y] == '1'){
            grid[x][y] = '0';
            if(x > 0){
                Recursion(grid, islands, x-1, y, n, m);
            }
            if(x < n-1){
                Recursion(grid, islands, x+1, y, n, m);
            }
            if(y > 0){
                Recursion(grid, islands, x, y-1, n, m);
            }
            if(y < m-1){
                Recursion(grid, islands, x, y+1, n, m);
            }
            islands.erase(x*m+y);
        }
        else{
            return;
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        unordered_set<int> islands;
        int n = grid.size();
        if(n == 0){
            return 0;
        }
        int m = grid[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == '1'){
                    islands.insert(i*m+j);
                }
            }
        }
        int count = 0;
        while(!islands.empty()){
            int x = *(islands.begin()) / m;
            int y = *(islands.begin()) % m ;
            Recursion(grid, islands, x, y, n, m);
            count++;
        }
        return count;
    }
};

int main(){
    unordered_set<int> a;
    int b = *(a.begin());
    
}

