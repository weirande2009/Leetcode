#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;




class Solution {
public:
    bool possible(vector<vector<int>>& candidates, int sum, int target, int layer){
        return false;
    }
    
    void dfs(vector<vector<int>>& result, vector<vector<int>>& candidates, vector<int>& cur, int sum, int layer, int target, int total){
        if(sum == target){
            result.push_back(cur);
            return;
        }
        if(layer == candidates.size()){
            return;
        }
        if(total+sum < target){
            return;
        }
        for(int i=0; i<=candidates[layer][1]; i++){
            for(int j=0; j<i; j++){
                cur.push_back(candidates[layer][0]);
            }
            if(sum+candidates[layer][0]*i <= target){
                dfs(result, candidates, cur, sum+candidates[layer][0]*i, layer+1, target, total-candidates[layer][1]*candidates[layer][0]);
            }
            for(int j=0; j<i; j++){
                cur.erase(cur.begin()+cur.size()-1);
            }
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> cur;
        vector<vector<int>> can;
        unordered_map<int, int> hashtable;
        for(int i=0; i<candidates.size(); i++){
            if(candidates[i] > target){
                continue;
            }
            if(hashtable.find(candidates[i]) == hashtable.end()){
                hashtable[candidates[i]] = 1;
            }
            else{
                hashtable[candidates[i]]++;
            }
        }
        for(auto a: hashtable){
            can.push_back({a.first, a.second});
        }
        sort(can.begin(), can.end(), [](const vector<int>& v1, const vector<int>& v2){
            return v1[0] > v2[0];
        });
        int total = 0;
        for(int i=0; i<candidates.size(); i++){
            if(candidates[i] <= target){
                total += candidates[i];
            }
        }
        for(int i=0; i<can.size(); i++){
            can[i][1] = min(can[i][1], target/can[i][0]);
        }
        dfs(result, can, cur, 0, 0, target, total);
        return result;
    }
};