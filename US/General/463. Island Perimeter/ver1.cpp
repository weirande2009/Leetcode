#include <vector>
using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int count = 0;
        vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j] == 1){
                    count += 4;
                    for(int k=0; k<4; k++){
                        int r = i+directions[k][0];
                        int c = j+directions[k][1];
                        if(r >= 0 && r < row && c >= 0 && c < col){
                            if(grid[r][c] == 1){
                                count--;
                            }
                        }
                    }
                }
            }
        }
        return count;
    }
};