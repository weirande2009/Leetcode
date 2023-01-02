#include <vector>
using namespace std;


class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> less_from_left(n, -1);
        vector<int> less_from_right(n, n);

        // compute less from left
        for(int i=1; i<n; i++){
            int p = i-1;
            while(p >= 0 && heights[p] >= heights[i]){
                // jump to find the first less
                p = less_from_left[p];
            }
            less_from_left[i] = p;
        }
        // compute less from right
        for(int i=n-2; i>=0; i--){
            int p = i+1;
            while(p < n && heights[p] >= heights[i]){
                // jump to find the first less
                p = less_from_right[p];
            }
            less_from_right[i] = p;
        }
        int result = 0;
        for(int i=0; i<n; i++){
            result = max(result, heights[i] * (less_from_right[i] - less_from_left[i] - 1));
        }
        return result;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        // heights[i][j] means the max height of the points (i, j)
        vector<vector<int>> heights(n, vector<int>(m, 0));
        for(int i=0; i<m; i++){
            heights[0][i] = matrix[0][i] == '1' ? 1 : 0;
        }
        for(int i=1; i<n; i++){
            for(int j=0; j<m; j++){
                heights[i][j] = matrix[i][j] == '1' ? heights[i-1][j]+1 : 0;
            }
        }
        int result = 0;
        // now we have the height of each points (i, j), we can regard a row of points as a histogram for the problem of largestRectangleArea
        for(int i=0; i<n; i++){
            result = max(result, largestRectangleArea(heights[i]));
        }
        return result;
    }
};