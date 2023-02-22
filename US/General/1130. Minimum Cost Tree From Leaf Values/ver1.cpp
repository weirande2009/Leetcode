#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    pair<int, int> dfs(vector<int>& arr, vector<vector<vector<int>>>& memo, int start, int end){
        if(start == end){
            return {0, arr[start]};
        }
        if(memo[start][end][0] != -1){
            return {memo[start][end][0], memo[start][end][1]};
        }
        int sum = INT_MAX;
        int max_leaf = 0;
        for(int i=start; i<end; i++){
            pair<int, int> left = dfs(arr, memo, start, i);
            pair<int, int> right = dfs(arr, memo, i+1, end);
            max_leaf = max(max_leaf, max(left.second, right.second));
            sum = min(sum, left.first + right.first + left.second * right.second);
        }
        memo[start][end][0] = sum;
        memo[start][end][1] = max_leaf;
        return {sum, max_leaf};
    }

    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        // memo[i][j] means the min sum of leaves from i to j
        vector<vector<vector<int>>> memo(n, vector<vector<int>>(n, vector<int>(2, -1)));
        return dfs(arr, memo, 0, arr.size()-1).first;
    }
};