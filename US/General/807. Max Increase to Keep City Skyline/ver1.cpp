#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        // 0 means top to bottom, 1 means left to right
        vector<vector<int>> contours(n, vector<int>(2, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                contours[i][1] = max(contours[i][1], grid[i][j]);
                contours[j][0] = max(contours[j][0], grid[i][j]);
            }
        }
        int increment = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                increment += min(contours[i][1], contours[j][0]) - grid[i][j];
            }
        }
        return increment;
    }
};