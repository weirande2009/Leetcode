#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    void dfs(vector<vector<int>>& result, vector<int>& candidates, vector<int>& cur, int left, int layer){
        if(layer == candidates.size()-1){
            if(left%candidates[layer] != 0){
                return;
            }
            else{
                int n = left / candidates[layer];
                for(int j=0; j<n; j++){
                    cur.push_back(candidates[layer]);
                }
                result.push_back(cur);
                int s = cur.size();
                for(int j=0; j<n; j++){
                    cur.erase(cur.begin()+s-1-j);
                }
                return;
            }
        }
        int n = left / candidates[layer];
        for(int i=0; i<=n; i++){
            for(int j=0; j<i; j++){
                cur.push_back(candidates[layer]);
            }
            if(left-i*candidates[layer] == 0){
                result.push_back(cur);
            }
            else{
                dfs(result, candidates, cur, left-i*candidates[layer], layer+1);
            }
            int s = cur.size();
            for(int j=0; j<i; j++){
                cur.erase(cur.begin()+s-1-j);
            }
        }
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end(), [](int a, int b){return a>b;});
        vector<vector<int>> result;
        vector<int> cur;
        dfs(result, candidates, cur, target, 0);
        return result;
    }
};