#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(m == 0){
            return {};
        }
        int n = matrix[0].size();
        vector<vector<int>> direction = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        int direction_kind = 0;
        vector<vector<bool>> visited(m+2, vector<bool>(n+2, false));
        // Set the outermost true
        for(int i=0; i<n+2; i++){
            visited[0][i] = true;
            visited[m+1][i] = true;
        }
        for(int i=0; i<m+2; i++){
            visited[i][0] = true;
            visited[i][n+1] = true;
        }
        int i = 0;
        int j = 0;
        vector<int> result;
        while(1){
            result.push_back(matrix[i][j]);
            visited[i+1][j+1] = true;
            int tmp_i = i + direction[direction_kind][0];
            int tmp_j = j + direction[direction_kind][1];
            if(visited[tmp_i+1][tmp_j+1]){
                direction_kind = (direction_kind+1) % 4;
                tmp_i = i + direction[direction_kind][0];
                tmp_j = j + direction[direction_kind][1];
                // After changing direction, still visited, over
                if(visited[tmp_i+1][tmp_j+1]){
                    break;
                }
            }
            i = tmp_i;
            j = tmp_j;
        }
        return result;
    }
};

int main()
{
    vector<vector<int>> matrix = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};
    Solution s;
    s.spiralOrder(matrix);
    return 0;
}

