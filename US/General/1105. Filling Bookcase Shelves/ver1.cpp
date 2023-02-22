#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dfs(vector<vector<int>>& books, vector<int>& memo, int i, int shelfWidth){
        int n = books.size();
        if(i == n){
            return 0;
        }
        if(memo[i] != -1){
            return memo[i];
        }
        // put in the same level
        int min_height = INT_MAX;
        int thickness = 0;
        int height = 0;
        for(int j=i; j<n; j++){
            thickness += books[j][0];
            height = max(height, books[j][1]);
            if(thickness <= shelfWidth){
                min_height = min(min_height, height + dfs(books, memo, j+1, shelfWidth));
            }
            else{
                break;
            }
        }
        memo[i] = min_height;
        return min_height;
    }

    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<int> memo(n, -1);
        return dfs(books, memo, 0, shelfWidth);
    }
};