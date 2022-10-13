#include <vector>
using namespace std;

// Algorithm: In-place. Use -1 or 0 to represent origin 0 and 1 or 2 to represent origin
// 1. -1 means 0 becomes 1. 2 means 1 becomes 0. We can separate origin and next state
// while we can also identify it's origin value.

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
                        if(board[i][j] >= 1)
                            s += 1;
                    }
                }
            }
        }
        return s;
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int s = sumOfNeighbors(board, i, j, n, m);
                if(board[i][j] == 1){
                    if(s < 2 || s > 3){
                        board[i][j] = 2;
                    }
                    else{
                        board[i][j] = 1;
                    }
                }
                else{
                    if(s == 3){
                        board[i][j] = -1;
                    }
                    else{
                        board[i][j] = 0;
                    }
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == -1){
                    board[i][j] = 1;
                }
                else if(board[i][j] == 2){
                    board[i][j] = 0;
                }
            }
        }
    }
};