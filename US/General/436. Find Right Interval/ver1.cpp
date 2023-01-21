#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> new_intervals(n);
        for(int i=0; i<n; i++){
            new_intervals[i] = intervals[i];
            new_intervals[i].push_back(i);
        }
        // sort by end
        sort(new_intervals.begin(), new_intervals.end(), [](const vector<int>& v1, const vector<int>& v2){
            return v1[0] < v2[0];
        });
        vector<int> ans;
        for(auto& v: intervals){
            int low = 0;
            int high = n-1;
            while(low <= high){
                int mid = (low+high) / 2;
                if(new_intervals[mid][0] >= v[1]){
                    high = mid-1;
                }
                else{
                    low = mid+1;
                }
            }
            if(low < n){
                ans.push_back(new_intervals[low][2]);
            }
            else{
                ans.push_back(-1);
            }
        }
        return ans;
    }
};