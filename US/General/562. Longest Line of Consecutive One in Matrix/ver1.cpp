#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestLine(vector<vector<int>>& mat) {
        int ans = 0;
        int m = mat.size();
        int n = mat[0].size();
        // horizontal
        for(int i=0; i<m; i++){
            int begin = -1;
            for(int j=0; j<n; j++){
                if(mat[i][j] == 1){
                    if(begin == -1){
                        begin = j;
                    }
                    ans = max(ans, j-begin+1);
                }
                else{
                    if(begin != -1){
                        begin = -1;
                    }
                }
            }
        }
        // vertical
        for(int i=0; i<n; i++){
            int begin = -1;
            for(int j=0; j<m; j++){
                if(mat[j][i] == 1){
                    if(begin == -1){
                        begin = j;
                    }
                    ans = max(ans, j-begin+1);
                }
                else{
                    if(begin != -1){
                        begin = -1;
                    }
                }
            }
        }
        // diagonal
        for(int i=0; i<n; i++){
            int begin = -1;
            for(int j=0; j<min(m, n); j++){
                if(j+i >= n || j >= m){
                    break;
                }
                if(mat[j][j+i] == 1){
                    if(begin == -1){
                        begin = j;
                    }
                   ans = max(ans, j-begin+1);
                }
                else{
                    if(begin != -1){
                        begin = -1;
                    }
                }
            }
        }
        for(int i=1; i<m; i++){
            int begin = -1;
            for(int j=0; j<min(m, n); j++){
                if(j+i >= m || j >= n){
                    break;
                }
                if(mat[j+i][j] == 1){
                    if(begin == -1){
                        begin = j;
                    }
                    ans = max(ans, j-begin+1);
                }
                else{
                    if(begin != -1){
                        begin = -1;
                    }
                }
            }
        }
        //anti-diagonal
        for(int i=0; i<n; i++){
            int begin = -1;
            for(int j=0; j<min(m, n); j++){
                if(m-j-1 < 0 || j+i >= n){
                    break;
                }
                if(mat[m-j-1][j+i] == 1){
                    if(begin == -1){
                        begin = j;
                    }
                    ans = max(ans, j-begin+1);
                }
                else{
                    if(begin != -1){
                        begin = -1;
                    }
                }
            }
        }
        for(int i=0; i<m-1; i++){
            int begin = -1;
            for(int j=0; j<min(m, n); j++){
                if(i-j < 0 || j >= n){
                    break;
                }
                if(mat[i-j][j] == 1){
                    if(begin == -1){
                        begin = j;
                    }
                    ans = max(ans, j-begin+1);
                }
                else{
                    if(begin != -1){
                        begin = -1;
                    }
                }
            }
        }
        return ans;
    }
};