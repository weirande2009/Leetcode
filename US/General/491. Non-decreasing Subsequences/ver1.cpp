#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    void dfs(vector<int>& nums, set<vector<int>>& ans, vector<int>& route, int pos){
        if(pos == nums.size()){
            if(route.size() >= 2){
                ans.insert(route);
            }
            return;
        }
        // don't choose the current number
        dfs(nums, ans, route, pos+1);
        // choose the current number
        if(route.empty() || nums[pos] >= route.back()){
            route.push_back(nums[pos]);
            dfs(nums, ans, route, pos+1);
            route.pop_back();
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> ans;
        vector<int> route;
        dfs(nums, ans, route, 0);
        return vector<vector<int>>(ans.begin(), ans.end());
    }
};