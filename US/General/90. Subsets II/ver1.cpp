#include <vector>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& result, vector<int>& cur, vector<vector<int>>& nums, int layer){
        if(layer == nums.size()){
            result.push_back(cur);
            return;
        }
        for(int i=0; i<=nums[layer][1]; i++){
            for(int j=0; j<i; j++){
                cur.push_back(nums[layer][0]);
            }
            dfs(result, cur, nums, layer+1);
            for(int j=0; j<i; j++){
                cur.erase(cur.begin()+cur.size()-1);
            }
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        unordered_map<int, int> hashtable;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(hashtable.find(nums[i]) == hashtable.end()){
                hashtable[nums[i]] = 1;
            }
            else{
                hashtable[nums[i]]++;
            }
        }
        vector<vector<int>> numbers;
        for(auto a: hashtable){
            numbers.push_back({a.first, a.second});
        }
        vector<vector<int>> result;
        vector<int> cur;
        dfs(result, cur, numbers, 0);
        return result;
    }
};