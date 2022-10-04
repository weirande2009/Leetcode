#include <vector>
#include <algorithm>
using namespace std;

// Algorithm: O(nlogn). Sort the invervals. Traverse the array to find overlapping intervals.
// When finding one, judge the right border of the two and choose the smaller one as the current
// vector, which means remove the bigger one.

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), [](const vector<int>& v1, const vector<int>& v2){
            // return v1[0] < v2[0] || v1[0] == v2[0] && v1[1] < v2[1];
            return v1[1] < v2[1];
        });
        int r = 0;
        vector<int> cur_interval = intervals[0];
        for(int i=1; i<n; i++){
            if(intervals[i][0] < cur_interval[1]){  // overlapping
                if(intervals[i][1] < cur_interval[1]){
                    cur_interval[0] = intervals[i][0];
                    cur_interval[1] = intervals[i][1];
                }
                r++;
            }
            else{
                cur_interval[0] = intervals[i][0];
                cur_interval[1] = intervals[i][1];
            }
        }
        return r;
    }
};
