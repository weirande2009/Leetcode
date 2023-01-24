#include <vector>
using namespace std;

class Solution {
public:
    int dfs(vector<int>& boxes, vector<vector<vector<int>>>& dp, int l, int r, int k){
        if(l > r){
            return 0;
        }

        // compute the number of the similar number at the end
        while(l < r && boxes[r] == boxes[r-1]){
            r--;
            k++;
        }
        if(dp[l][r][k] != 0){
            return dp[l][r][k];
        }

        // set the entry, which is removing all the similar numbers at the end
        dp[l][r][k] = dfs(boxes, dp, l, r-1, 0) + (k+1) * (k+1);

        // iterate over the arr and find the similar number as boxes[r]
        for(int i=l; i<r; i++){
            if(boxes[i] == boxes[r]){
                dp[l][r][k] = max(dp[l][r][k], dfs(boxes, dp, l, i, k+1)+dfs(boxes, dp, i+1, r-1, 0));
            }
        }
        return dp[l][r][k];
    }

    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, 0)));
        return dfs(boxes, dp, 0, n-1, 0);
    }
};