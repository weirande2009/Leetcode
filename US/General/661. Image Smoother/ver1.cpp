#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        vector<vector<int>> ans = img;
        int m = img.size();
        int n = img[0].size();
        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int count = 1;
                int sum = img[i][j];
                for(int k=0; k<8; k++){
                    int r = i + directions[k][0];
                    int c = j + directions[k][1];
                    if(r < 0 || r >= m || c < 0 || c >= n){
                        continue;
                    }
                    sum += img[r][c];
                    count++;
                }
                ans[i][j] = sum / count;
            }
        }
        return ans;
    }
};