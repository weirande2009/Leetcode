#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        vector<vector<int>> positions(3);
        for(int i=0; i<colors.size(); i++){
            positions[colors[i]-1].push_back(i);
        }

        vector<int> ans;
        for(int i=0; i<queries.size(); i++){
            if(positions[queries[i][1]-1].size() == 0){
                ans.push_back(-1);
                continue;
            }
            auto it = lower_bound(positions[queries[i][1]-1].begin(), positions[queries[i][1]-1].end(), queries[i][0]);
            if(it == positions[queries[i][1]-1].begin()){
                ans.push_back((*it)-queries[i][0]);
            }
            else if(it == positions[queries[i][1]-1].end()){
                ans.push_back(queries[i][0]-*(it-1));
            }
            else{
                ans.push_back(min((*it)-queries[i][0], queries[i][0]-(*(it-1))));
            }
        }
        return ans;
    }
};