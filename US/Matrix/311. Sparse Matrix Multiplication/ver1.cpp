#include <vector>
using namespace std;


class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        int mat1_n = mat1.size();
        int mat1_m = mat1[0].size();
        int mat2_n = mat2.size();
        int mat2_m = mat2[0].size();
        vector<vector<int>> result(mat1_n, vector<int>(mat2_m, 0));
        for(int i=0; i<mat1_n; i++){
            for(int j=0; j<mat2_m; j++){
                for(int k=0; k<mat1_m; k++){
                    if(mat1[i][k] != 0 && mat2[k][j] != 0){
                        result[i][j] += mat1[i][k]*mat2[k][j];
                    }
                }
            }
        }
        return result;
    }
};