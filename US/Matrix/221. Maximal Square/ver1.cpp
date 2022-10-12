#include <vector>
using namespace std;


class Solution {
public:
    vector<vector<char>> Rotate(vector<vector<char>>& matrix){
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<char>> new_matrix(m, vector<char>(n));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                new_matrix[j][i] = matrix[i][j];
            }
        }
        return new_matrix;
    }
    
    int maximalSquare(const vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int max_area = 0;
        int max_side = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(m-j <= max_side){
                    break;
                }
                if(matrix[i][j] == '1'){
                    if(1 > max_area){
                        max_area = 1;
                        max_side = 1;
                    }
                    int num = 0;
                    for(int k=j; k<m; k++){
                        if(matrix[i][k] == '1'){
                            num++;
                        }   
                        else{
                            break;
                        }
                    }
                    if(num <= max_side){
                        continue;
                    }
                    int col = 1;
                    bool flag = false;
                    for(int l=i+1; l<n; l++){
                        for(int o=j; o<j+num; o++){
                            if(matrix[l][o] != '1'){
                                if(o == j){
                                    flag = true;
                                }
                                else{
                                    num = o-j;
                                }
                                break;
                            }
                        }
                        if(flag){
                            break;
                        }
                        col++;
                        int side = col > num ? num : col;
                        if(side*side > max_area){
                            max_area = side*side;
                            max_side = side;
                        }
                    }
                }
            }
        }
        return max_area;
    }
};