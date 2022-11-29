#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int mn = INT_MAX;
        for(int i=1; i<n; i++){
            mn = min(mn, arr[i]-arr[i-1]);
        }
        vector<vector<int>> result;
        for(int i=1; i<n; i++){
            if(arr[i] - arr[i-1] == mn){
                result.push_back({arr[i-1], arr[i]});
            }
        }
        return result;
        
    }
};