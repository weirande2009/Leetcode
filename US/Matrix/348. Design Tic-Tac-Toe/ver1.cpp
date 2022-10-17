#include <vector>
using namespace std;

// Algorithm: use vector to record the sum of each row and col.

class TicTacToe {
private:
    vector<vector<int>> board;
    vector<int> row_sum;
    vector<int> column_sum;
    vector<int> diag_sum;
    int num;
    
public:
    TicTacToe(int n) {
        num = n;
        board = vector<vector<int>>(n, vector<int>(n, 0));
        row_sum = vector<int>(n, 0);
        column_sum = vector<int>(n, 0);
        diag_sum = vector<int>(2, 0);
    }
    
    int move(int row, int col, int player) {
        int piece = 0;
        if(player == 1){
            piece = 1;
        }
        else if(player == 2){
            piece = -1;
        }
        row_sum[row] += piece;
        column_sum[col] += piece;
        if(row == col){
            diag_sum[0] += piece;
            if(diag_sum[0] == piece*num){
                return player;
            }
        }
        if(row == num-col-1){
            diag_sum[1] += piece;
            if(diag_sum[1] == piece*num){
                return player;
            }
        }
        if(row_sum[row] == piece*num){
            return player;
        }
        if(column_sum[col] == piece*num){
            return player;
        }
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */