#include <vector>
using namespace std;

// Algorithm: Allocate a new board

class Solution {
public:
    int sumOfNeighbors(const vector<vector<int>>& board, int x, int y, int n, int m){
        int s = 0;
        for(int i=x-1; i<x+2; i++){
            if(i >= 0 && i <= n-1){
                for(int j=y-1; j<y+2; j++){
                    if(j >= 0 && j <= m-1){
                        if(i == x && j == y){
                            continue;
                        }
                        s += board[i][j];
                    }
                }
            }
        }
        return s;
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> next(n, vector<int>(m));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int s = sumOfNeighbors(board, i, j, n, m);
                if(board[i][j] == 1){
                    if(s < 2 || s > 3){
                        next[i][j] = 0;
                    }
                    else{
                        next[i][j] = 1;
                    }
                }
                else{
                    if(s == 3){
                        next[i][j] = 1;
                    }
                    else{
                        next[i][j] = 0;
                    }
                }
            }
        }
        board = next;
    }
};