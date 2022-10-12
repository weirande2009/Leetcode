#include <vector>
using namespace std;


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i=0; i<n/2; i++){
            int border = n-2*i-1;
            for(int j=0; j<border; j++){
                int tmp = matrix[i][i+j];
                matrix[i][i+j] = matrix[i+border-j][i];
                matrix[i+border-j][i] = matrix[i+border][i+border-j];
                matrix[i+border][i+border-j] = matrix[i+j][i+border];
                matrix[i+j][i+border] = tmp;
            }
        }
    }
};