#include <vector>
using namespace std;

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        int count = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == 'X'){
                    count++;
                    // find vertically
                    int c = 1;
                    for(int k=i+1; k<m; k++){
                        if(board[k][j] == 'X'){
                            board[k][j] = '.';
                            c++;
                        }
                        else{
                            break;
                        }
                    }
                    if(c > 1){
                        continue;
                    }
                    // find horizontally
                    for(int k=j+1; k<n; k++){
                        if(board[i][k] == 'X'){
                            board[i][k] = '.';
                            c++;
                        }
                        else{
                            break;
                        }
                    }
                }
            }
        }
        return count;
    }
};