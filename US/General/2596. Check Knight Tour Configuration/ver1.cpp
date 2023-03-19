#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> directions = {{-2, 1}, {-1, 2}, {2, 1}, {1, 2}, {-2, -1}, {-1, -2}, {2, -1}, {1, -2}};
        int num = 0;
        int target = n*n - 1;
        int row = 0;
        int col = 0;
        while(1){
            bool found = false;
            for(int i=0; i<8; i++){
                int r = row + directions[i][0];
                int c = col + directions[i][1];
                if(r < 0 || r >= n || c < 0 || c >= n || grid[r][c] != num+1){
                    continue;
                }
                row = r;
                col = c;
                found = true;
                num++;
                break;
            }
            if(!found){
                return false;
            }
            if(num == target){
                return true;
            }
        }
        return false;
    }
};