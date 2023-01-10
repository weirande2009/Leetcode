#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> mat(n, vector<int>(n, 0));
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int i = 1;
        int x = 0;
        int y = 0;
        int d = 0;
        while(i <= n*n){
            mat[y][x] = i;
            visited[y][x] = true;
            if(y+directions[d][0] >= n || y+directions[d][0] < 0 || x+directions[d][1] >= n || x+directions[d][1] < 0 || visited[y+directions[d][0]][x+directions[d][1]]){
                d = (d+1) % 4;
            }
            y += directions[d][0];
            x += directions[d][1];
            i++;
        }
        return mat;
    }
};
