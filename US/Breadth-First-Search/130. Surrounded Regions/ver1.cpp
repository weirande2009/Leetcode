#include <vector>
#include <queue>
using namespace std;

// Algorithm: We only need to find all 'O's that are adjacent to the border 'O'. Use DFS to 
// search from every border 'O' and record all 'O' that in the search. Then set all 'O' that
// are not recorded as 'X'.


class Solution {
public:
    
    void Recursion(vector<vector<char>>& board, vector<vector<bool>>& visited, int x, int y, int n, int m){
        if(board[x][y] == 'O' && !visited[x][y]){
            visited[x][y] = true;
            if(x > 0){
                Recursion(board, visited, x-1, y, n, m);
            }
            if(x < n-1){
                Recursion(board, visited, x+1, y, n, m);
            }
            if(y > 0){
                Recursion(board, visited, x, y-1, n, m);
            }
            if(y < m-1){
                Recursion(board, visited, x, y+1, n, m);
            }
        }
        else{
            return;
        }
    }
    
    void solve(vector<vector<char>>& board) {
        queue<int> border_o;
        int n = board.size();
        if(n == 0){
            return;
        }
        int m = board[0].size();
        for(int i=0; i<n; i++){
            if(board[i][0] == 'O'){
                border_o.push(i*m);
            }
            if(board[i][m-1] == 'O'){
                border_o.push(i*m+m-1);
            }
        }
        for(int i=1; i<m-1; i++){
            if(board[0][i] == 'O'){
                border_o.push(i);
            }
            if(board[n-1][i] == 'O'){
                border_o.push((n-1)*m+i);
            }
        }
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        while(!border_o.empty()){
            int x = border_o.front() / m;
            int y = border_o.front() % m ;
            Recursion(board, visited, x, y, n, m);
            border_o.pop();
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == 'O' && !visited[i][j]){
                    board[i][j] = 'X';
                }
            }
        }
    }
};