#include <vector>
using namespace std;

// Algorithm: dp with dfs, from top to down, compute the cost of paint house red, blue or green

class Solution {
public:
    vector<int> dfs(vector<vector<int>>& costs, int layer, int n){
        if(layer == n-1){
            return costs[layer];
        }
        vector<int> after = dfs(costs, layer+1, n);
        int red = min(after[1], after[2]) + costs[layer][0];
        int blue = min(after[0], after[2]) + costs[layer][1];
        int green = min(after[0], after[1]) + costs[layer][2];
        return {red, blue, green};
    }
    
    
    int minCost(vector<vector<int>>& costs) {
        vector<int> result = dfs(costs, 0, costs.size());
        return min(result[0], min(result[1], result[2]));
    }
};