#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        for(vector<int>& query: queries){
            // for the first row, if we want to add one between query[1] and query[3],
            // we can add one to query[1] and delete one from query[3]+1,
            // After that, we do a prefix sum on each row and column and can get what we want.
            matrix[query[0]][query[1]]++;
            if(query[3]+1 < n){
                matrix[query[0]][query[3]+1]--;
            }
            // Then we can do the same to the first column
            if(query[2]+1 < n){
                matrix[query[2]+1][query[1]]--;
                // if both (query[0], query[3]+1) and (query[2]+1, query[1]) is decreased, we need to increase the right bottom one
                // because when we do the prefix sum, it's decreased twice
                if(query[3]+1 < n){
                    matrix[query[2]+1][query[3]+1]++;
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=1; j<n; j++){
                matrix[i][j] += matrix[i][j-1];
            }
        }
        for(int i=1; i<n; i++){
            for(int j=0; j<n; j++){
                matrix[i][j] += matrix[i-1][j];
            }
        }
        return matrix;
    }
};