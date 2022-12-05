#include <vector>
#include <limits.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int n = intervals.size();
        int start = INT_MAX;
        int end = 0;
        for(int i=0; i<n; i++){
            if(intervals[i][1] >= newInterval[0] && intervals[i][1] <= newInterval[1] || newInterval[1] >= intervals[i][0] && newInterval[1] <= intervals[i][1]){
                start = min(start, min(intervals[i][0], newInterval[0]));
                end = max(end, max(intervals[i][1], newInterval[1]));
            }
        }
        if(start == INT_MAX){
            start = newInterval[0];
            end = newInterval[1];
        }
        bool added = false;
        for(int i=0; i<n; i++){
            if(!(intervals[i][1] >= start && intervals[i][1] <= end || end >= intervals[i][0] && end <= intervals[i][1])){
                if(!added && intervals[i][0] > end){
                    result.push_back({start, end});
                    added = true;
                }
                result.push_back(intervals[i]);
            }
        }
        if(!added){
            result.push_back({start, end});
        }
        return result;
    }
};