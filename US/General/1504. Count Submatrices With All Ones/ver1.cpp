#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> consecutive_from_top(m, vector<int>(n, 0));
        int count = 0;
        for(int i=0; i<n; i++){
            consecutive_from_top[0][i] = mat[0][i];
            for(int j=i; j>=0; j--){
                if(consecutive_from_top[0][j] == 0){
                    break;
                }
                count += consecutive_from_top[0][j];
            }
        }
        for(int i=1; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j] == 0){
                    continue;
                }
                // max height of the matrix is the consecutive ones from mat[0][j] to mat[i][j]
                consecutive_from_top[i][j] = consecutive_from_top[i-1][j] + 1;
                int mx_height = consecutive_from_top[i][j];
                for(int k=j; k>=0; k--){
                    if(consecutive_from_top[i][k] == 0){
                        break;
                    }
                    mx_height = min(mx_height, consecutive_from_top[i][k]);
                    count += mx_height;
                }
            }
        }
        return count;
    }
};