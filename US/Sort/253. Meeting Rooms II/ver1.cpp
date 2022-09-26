#include <vector>
#include <algorithm>
using namespace std;

// Algorithm: O(nlogn). Sort. Use a vector to include the end time for each room.
// If pre begin time less than all the end time of each room, add a new room.

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n == 0){
            return true;
        }
        sort(intervals.begin(), intervals.end(), [](const vector<int>& v1, const vector<int>& v2){return v1[0] < v2[0];});
        vector<int> room_end_time(1, 0);
        for(int i=0; i<n; i++){
            int flag = false;
            for(int j=0; j<room_end_time.size(); j++){
                if(intervals[i][0] >= room_end_time[j]){
                    flag = true;
                    room_end_time[j] = intervals[i][1];
                    break;
                }
            }
            if(!flag){
                room_end_time.push_back(intervals[i][1]);
            }
        }
        return room_end_time.size();
    }
};