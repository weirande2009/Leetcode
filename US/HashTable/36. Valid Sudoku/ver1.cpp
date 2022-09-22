#include <vector>
#include <unordered_set>
using namespace std;

// Algorithm: Use hashtable to record all valid number in a row/column/3*3 grid.

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row = board.size();
        int column = board[0].size();
        // Row
        for(int i=0; i<row; i++){
            unordered_set<char> hashtable;
            for(int j=0; j<column; j++){
                if(board[i][j] != '.'){
                    auto f = hashtable.find(board[i][j]);
                    if(f == hashtable.end()){
                        hashtable.insert(board[i][j]);
                    }
                    else{
                        return false;
                    }
                }
            }
        }
        // Column
        for(int i=0; i<column; i++){
            unordered_set<char> hashtable;
            for(int j=0; j<row; j++){
                if(board[j][i] != '.'){
                    auto f = hashtable.find(board[j][i]);
                    if(f == hashtable.end()){
                        hashtable.insert(board[j][i]);
                    }
                    else{
                        return false;
                    }
                }
            }
        }
        // 3*3 grid
        for(int i=0; i<9; i++){
            int begin_row = i/3*3;
            int begin_column = i%3*3;
            unordered_set<char> hashtable;
            for(int j=begin_row; j<begin_row+3; j++){
                for(int k=begin_column; k<begin_column+3; k++){
                    if(board[j][k] != '.'){
                        auto f = hashtable.find(board[j][k]);
                        if(f == hashtable.end()){
                            hashtable.insert(board[j][k]);
                        }
                        else{
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};