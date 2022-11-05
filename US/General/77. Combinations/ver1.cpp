#include <vector>
using namespace std;


class Solution {
public:
    void dfs(vector<vector<int>>& result, vector<int>& cur, int layer, int n, int k){
        if(cur.size() == k){
            result.push_back(cur);
            return;
        }
        if(n-layer+cur.size() < k){
            return;
        }
        // choose layer
        cur.push_back(layer+1);
        dfs(result, cur, layer+1, n, k);
        cur.erase(cur.begin()+cur.size()-1);
        // not choose layer
        dfs(result, cur, layer+1, n, k);
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> cur;
        dfs(result, cur, 0, n, k);
        return result;
    }
};