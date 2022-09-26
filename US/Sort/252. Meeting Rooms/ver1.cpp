#include <vector>
#include <algorithm>
using namespace std;

// Algorithm: Sort and traverse.

class Solution {
public:
    
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n == 0){
            return true;
        }
        sort(intervals.begin(), intervals.end(), [](const vector<int>& v1, const vector<int>& v2){return v1[0] < v2[0];});
        vector<int> pre = intervals[0];
        for(int i=1; i<n; i++){
            if(intervals[i][0] < pre[1]){
                return false;
            }
            pre = intervals[i];
        }
        return true;
    }
};
