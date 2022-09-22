#include <stack>
#include <vector>
#include <functional>
using namespace std;

class Pos{
public:
    int x;
    int y;
    Pos(){}
    Pos(int _x, int _y) : x(_x), y(_y){}
    bool operator==(const Pos& other){
        if(other.x == x && other.y == y){
            return true;
        }
        return false;
    }
};

class Solution {
private:
    int m;
    int n;
    bool found = false;
    vector<vector<bool>> visited;

public:
    bool InBoard(const Pos& pos){
        if(pos.x < 0 || pos.x >= n){
            return false;
        }
        if(pos.y < 0 || pos.y >= m){
            return false;
        }
        return true;
    }

    void RecursionFindWord(const vector<vector<char>>& board, const string& word, vector<Pos>& road, Pos pre_pos, int pre_char_pos){
        // 若已经找到，则直接返回
        if(found){
            return;
        }
        // 若当前位置的字符就是所要字符，则将当前位置加入到路径中
        if(board[pre_pos.y][pre_pos.x] == word[pre_char_pos]){
            visited[pre_pos.y][pre_pos.x] = true;
            if(pre_char_pos == word.length() - 1){  // 已经寻找完毕
                found = true;
                return;
            }
        }
        else{
            return;
        }
        Pos next_pos;
        // Up
        next_pos.x = pre_pos.x;
        next_pos.y = pre_pos.y - 1;
        if(InBoard(next_pos) && !visited[next_pos.y][next_pos.x]){  // 若在board中，且没有在走过的路径中
            RecursionFindWord(board, word, road, next_pos, pre_char_pos+1);
        }
        // Down
        next_pos.x = pre_pos.x;
        next_pos.y = pre_pos.y + 1;
        if(InBoard(next_pos) && !visited[next_pos.y][next_pos.x]){  // 若在board中，且没有在走过的路径中
            RecursionFindWord(board, word, road, next_pos, pre_char_pos+1);
        }
        // Left
        next_pos.x = pre_pos.x - 1;
        next_pos.y = pre_pos.y;
        if(InBoard(next_pos) && !visited[next_pos.y][next_pos.x]){  // 若在board中，且没有在走过的路径中
            RecursionFindWord(board, word, road, next_pos, pre_char_pos+1);
        }
        // Right
        next_pos.x = pre_pos.x + 1;
        next_pos.y = pre_pos.y;
        if(InBoard(next_pos) && !visited[next_pos.y][next_pos.x]){  // 若在board中，且没有在走过的路径中
            RecursionFindWord(board, word, road, next_pos, pre_char_pos+1);
        }
        // Delete from road
        visited[pre_pos.y][pre_pos.x]  = false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        for(int i=0; i<m; i++){
            vector<bool> visited_tmp;
            for(int j=0; j<n; j++){
                visited_tmp.push_back(false);
            }
            visited.push_back(visited_tmp);
        }
        vector<Pos> road;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                found = false;
                RecursionFindWord(board, word, road,  Pos(j, i), 0);
                if(found){
                    return true;
                }
            }
        }
        return false;
    }
};

int main(){
    vector<vector<char>> board;
    vector<char> board_1 = {'A', 'B', 'C', 'E'};
    vector<char> board_2 = {'S', 'F', 'C', 'S'};
    vector<char> board_3 = {'A', 'D', 'E', 'E'};
    board.push_back(board_1);
    board.push_back(board_2);
    board.push_back(board_3);
    string word = "SEE";

    Solution s;
    s.exist(board, word);
    return 0;
}