#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // count the number of consecutive 1s at the point (i,j) in row basis and column basis
        vector<vector<int>> rcount(m, vector<int>(n, 0));
        vector<vector<int>> ccount(m, vector<int>(n, 0));
        for(int i=0; i<m; i++){
            rcount[i][0] = grid[i][0];
        }
        for(int i=0; i<n; i++){
            ccount[0][i] = grid[0][i];
        }
        for(int i=0; i<m; i++){
            for(int j=1; j<n; j++){
                if(grid[i][j] == 1){
                    rcount[i][j] = rcount[i][j-1] + 1;
                }
            }
        }
        for(int i=1; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    ccount[i][j] = ccount[i-1][j] + 1;
                }
            }
        }
        int side = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    side = max(side, 1);
                    int r = rcount[i][j];
                    int c = ccount[i][j];
                    // iterate over each possible square
                    for(int k=1; k<min(r, c); k++){
                        if(rcount[i-k][j] >= k+1 && ccount[i][j-k] >= k+1){
                            side = max(side, k+1);
                        }
                    }
                }
            }
        }
        return side*side;
    }
};