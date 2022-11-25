#include <vector>
#include <unordered_set>
using namespace std;



class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = 9;
        vector<unordered_set<int>> row_hashtable(9);
        vector<unordered_set<int>> col_hashtable(9);
        vector<vector<unordered_set<int>>> grid_hashtable(9, vector<unordered_set<int>>(9));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] < '1' || board[i][j] > '9'){
                    continue;
                }
                if(row_hashtable[i].find(board[i][j]) == row_hashtable[i].end()){
                    row_hashtable[i].insert(board[i][j]);
                }
                else{
                    return false;
                }
                
                if(col_hashtable[j].find(board[i][j]) == col_hashtable[j].end()){
                    col_hashtable[j].insert(board[i][j]);
                }
                else{
                    return false;
                }
                
                if(grid_hashtable[i/3][j/3].find(board[i][j]) == grid_hashtable[i/3][j/3].end()){
                    grid_hashtable[i/3][j/3].insert(board[i][j]);
                }
                else{
                    return false;
                }
                
            }
        }
        return true;
        
    }
};