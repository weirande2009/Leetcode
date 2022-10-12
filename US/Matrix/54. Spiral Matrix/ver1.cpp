#include <vector>
#include <unordered_set>
using namespace std;


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        vector<vector<int>> directions;
        directions.push_back({0, 1});
        directions.push_back({1, 0});
        directions.push_back({0, -1});
        directions.push_back({-1, 0});
        unordered_set<int> route;
        int n = matrix.size();
        int m = matrix[0].size();
        int total = m*n;
        int dir = 0;
        int x = 0;
        int y = 0;
        while(route.size() < total){
           result.push_back(matrix[x][y]);
           route.insert(x*m+y);
           if(route.find((x+directions[dir][0])*m+y+directions[dir][1]) != route.end() || x+directions[dir][0] >= n || y+directions[dir][1] >= m){
               dir = (dir+1) % 4;
               x += directions[dir][0];
               y += directions[dir][1];
           }
           else{
               x += directions[dir][0];
               y += directions[dir][1];
            }
        }
        return result;
    }
};