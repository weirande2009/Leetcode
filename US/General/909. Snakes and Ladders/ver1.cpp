#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int compute_no(int y, int x, int n){
        int row = n-y-1;
        int col;
        if(row % 2 == 0){
            col = n-x-1;
        }
        else{
            col = x;
        }
        return row*n+col+1;
    }

    vector<int> compute_pos(int num, int n){
        int row = n - (num-1) / n - 1;
        int col;
        if((n-row) % 2 == 0){
            col = n - ((num-1) % n)-1;
        }
        else{
            col = (num-1)%n;
        }
        return {row, col};
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        queue<int> q;
        q.push(1);
        int steps = 0;
        vector<bool> visited(n*n, false);
        visited[0] = true;
        while(!q.empty()){
            queue<int> tmp_q;
            steps++;
            while(!q.empty()){
                int num = q.front();
                q.pop();
                for(int i=num+1; i<=min(num+6, n*n); i++){
                    vector<int> pos = compute_pos(i, n);
                    int tmp_num = -1;
                    if(!visited[i-1]){
                        visited[i-1] = true;
                        if(board[pos[0]][pos[1]] == -1){
                            tmp_num = i;
                        }
                        else{
                            if(!visited[board[pos[0]][pos[1]]-1] || board[pos[0]][pos[1]] < i){
                                tmp_num = board[pos[0]][pos[1]];
                            }
                        }
                        if(tmp_num == n*n){
                            return steps;
                        }
                        if(tmp_num != -1){
                            tmp_q.push(tmp_num);
                        }
                    }
                    
                }
            }
            q = tmp_q;
        }
        return -1;
    }
};