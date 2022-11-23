#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        if(n == 0){
            return 0;
        }
        
        // sort by x_end
        sort(points.begin(), points.end(), [](const vector<int>& v1, const vector<int>& v2){
            return v1[1] < v2[1];
        });
        
        int arrows = 1;
        // current start and end
        int x_start, x_end;
        // record the biggest end till now
        int first_end = points[0][1];
        for(auto p: points){
            x_start = p[0];
            x_end = p[1];
            // if the current ballon's starts after the biggest end till now, we'll start a 
            // new arrow
            if(first_end < x_start){
                arrows++;
                first_end = x_end;
            }
        }
        return arrows;
    }
};