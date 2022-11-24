#include <vector>
using namespace std;


class Solution {
public:
    void dfs(vector<vector<int>>& image, int i, int j, int color, int target, int m, int n){
        if(i < 0 || i >= m || j < 0 || j >= n){
            return;
        }
        if(image[i][j] == color){
            image[i][j] = target;
            vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
            for(int k=0; k<4; k++){
                int row = i + directions[k][0];
                int col = j + directions[k][1];
                dfs(image, row, col, color, target, m, n);
            }  
        }
    }
    
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] == color){
            return image;
        }
        dfs(image, sr, sc, image[sr][sc], color, image.size(), image[0].size());
        return image;
    }
};