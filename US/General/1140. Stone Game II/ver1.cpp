#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int canWin(vector<int>& piles, vector<vector<int>>& memo, int M, int i, int left_sum){
        int n = piles.size();
        int left = n - i;
        if(left <= 2*M){
            return left_sum;
        }
        if(memo[i][M] != -1){
            return memo[i][M];
        }
        int sum = 0;
        int ans = 0;
        for(int j=0; j<2*M; j++){
            sum += piles[i+j];
            ans = max(ans, left_sum-canWin(piles, memo, max(M, j+1), i+j+1, left_sum-sum));
        }
        memo[i][M] = ans;
        return ans;
    }

    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> memo(n, vector<int>(n, -1));
        int sum = accumulate(piles.begin(), piles.end(), 0);
        return canWin(piles, memo, 1, 0, sum);


    }
};