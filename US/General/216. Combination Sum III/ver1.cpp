#include <vector>
using namespace std;


class Solution {
public:
    void dfs(vector<vector<int>>& result, vector<int>& cur, int layer, int k, int n, int sum){
        if(sum == n){
            if(cur.size() == k){
                result.push_back(cur);
            }
            return;
        }
        if(cur.size() == k || layer == 9){
            return;
        }
        // use
        if(sum + layer + 1 <= n){
            cur.push_back(layer+1);
            dfs(result, cur, layer+1, k, n, sum+layer+1);
            cur.erase(cur.begin()+cur.size()-1);
        }
        // not use
        dfs(result, cur, layer+1, k, n, sum);
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> cur;
        dfs(result, cur, 0, k, n, 0);
        return result;
    }
};