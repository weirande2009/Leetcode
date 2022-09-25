#include <vector>
using namespace std;

// Algorithm: o(nlogn). First use quick sort to sort the intervals. Then just merge them.

class Solution {
public:
    void QuickSortForIntervals(vector<vector<int>>& intervals, int begin, int end){
        if(begin >= end){
            return;
        }
        int pivot = begin;
        for(int i=begin+1; i<=end; i++){
            if(intervals[i][0] < intervals[pivot][0]){
                if(pivot == i-1){
                    vector<int> tmp = intervals[pivot];
                    intervals[pivot] = intervals[i];
                    intervals[i] = tmp;
                }
                else{
                    // Exchange pivot and i
                    vector<int> tmp = intervals[pivot];
                    intervals[pivot] = intervals[i];
                    intervals[i] = tmp;
                    
                    // Exchange i and pivot+1
                    tmp = intervals[pivot+1];
                    intervals[pivot+1] = intervals[i];
                    intervals[i] = tmp;
                }
                pivot++;
            }
        }
        
        QuickSortForIntervals(intervals, begin, pivot-1);
        QuickSortForIntervals(intervals, pivot+1, end);
    }
    
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        QuickSortForIntervals(intervals, 0, n-1);
        vector<vector<int>> result;
        vector<int> pre_interval = intervals[0];
        for(int i=1; i<n; i++){
            if(intervals[i][0] > pre_interval[1]){
                result.push_back(pre_interval);
                pre_interval = intervals[i];
            }
            else{
                if(intervals[i][1] > pre_interval[1]){
                    pre_interval[1] = intervals[i][1];
                }
            }
        }
        result.push_back(pre_interval);
        return result;
    }
};