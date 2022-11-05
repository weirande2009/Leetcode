#include <vector>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& result, vector<int>& nums, int layer, vector<int>& cur){
        if(nums.size() == layer){
            result.push_back(cur);
            return;
        }
        dfs(result, nums, layer+1, cur);
        cur.push_back(nums[layer]);
        dfs(result, nums, layer+1, cur);
        cur.erase(cur.begin()+cur.size()-1);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> cur;
        dfs(result, nums, 0, cur);
        return result;
    }
};