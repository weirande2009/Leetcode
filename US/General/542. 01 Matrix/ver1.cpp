#include <vector>
#include <limits.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> distance(n, vector<int>(m, INT_MAX-1));
        // from left-top to right-bottom
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == 0){
                    distance[i][j] = 0;
                }
                else{
                    if(i > 0){
                        distance[i][j] = min(distance[i][j], distance[i-1][j]+1);
                    }
                    if(j > 0){
                        distance[i][j] = min(distance[i][j], distance[i][j-1]+1);
                    }
                }
            }
        }
        // backward
        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                if(i < n-1){
                    distance[i][j] = min(distance[i][j], distance[i+1][j]+1);
                }
                if(j < m-1){
                    distance[i][j] = min(distance[i][j], distance[i][j+1]+1);
                }
            }
        }
        return distance;
    }
};