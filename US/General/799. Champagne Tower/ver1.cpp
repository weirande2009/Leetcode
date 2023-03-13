#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> glasses(101, vector<double>(101, 0));
        glasses[0][0] = poured;
        for(int i=0; i<=query_row; i++){
            for(int j=0; j<=i; j++){
                if(glasses[i][j] > 1){
                    double extra = glasses[i][j]-1;
                    glasses[i+1][j] += extra / 2;
                    glasses[i+1][j+1] += extra / 2;
                    glasses[i][j] = 1;
                }
            }
        }
        return glasses[query_row][query_glass];
    }
};