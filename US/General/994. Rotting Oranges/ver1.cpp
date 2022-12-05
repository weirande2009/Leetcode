#include <vector>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        int round = 1;
        while(1){
            bool over = true;
            int fresh = 0;
            for(int i=0; i<m; i++){
                for(int j=0; j<n; j++){
                    if(grid[i][j]*round == 2){
                        if(i > 0){
                            if(grid[i-1][j] == 1){
                                grid[i-1][j] = -2*round;
                                over = false;
                            }
                        }
                        if(j > 0){
                            if(grid[i][j-1] == 1){
                                grid[i][j-1] = -2*round;
                                over = false;
                            }
                        }
                        if(i < m-1){
                            if(grid[i+1][j] == 1){
                                grid[i+1][j] = -2*round;
                                over = false;
                            }
                        }
                        if(j < n-1){
                            if(grid[i][j+1] == 1){
                                grid[i][j+1] = -2*round;
                                over = false;
                            }
                        }
                    }
                    else if(grid[i][j] == 1){
                        fresh++;
                    }
                }
            }
            if(over){
                if(fresh != 0){
                    return -1;
                }
                else{
                    break;
                }
            }
            round *= -1;
            count++;
        }
        return count;
    }
};