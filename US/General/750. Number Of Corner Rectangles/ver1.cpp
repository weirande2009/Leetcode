#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
        // count the number of pairs of row[i]=row[j]=1, key is i*200+j
        unordered_map<int, int> hashtable;
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    for(int k=j+1; k<m; k++){
                        if(grid[i][k] == 1){
                            int pos = j*200+k;
                            ans += hashtable[pos]++;
                        }
                    }
                }
            }
        }
        return ans;
    }
};