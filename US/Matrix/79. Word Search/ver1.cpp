#include <vector>
#include <string>
#include <unordered_set>
using namespace std;


class Solution {
public:
    
    void Search(const vector<vector<char>>& board, const string& word, int layer, unordered_set<int>& route, int x, int y, int n, int m, bool& found){
        if(found){
            return;
        }
        if(layer == word.length()){
            found = true;
            return;
        }
        route.insert(x*m+y);
        if(x > 0 && route.find((x-1)*m+y) == route.end()){
            if(board[x-1][y] == word[layer]){
                Search(board, word, layer+1, route, x-1, y, n, m, found);
            }
        }
        if(found){
            return;
        }
        if(x < n-1 && route.find((x+1)*m+y) == route.end()){
            if(board[x+1][y] == word[layer]){
                Search(board, word, layer+1, route, x+1, y, n, m, found);
            }
        }
        if(found){
            return;
        }
        if(y > 0 && route.find(x*m+y-1) == route.end()){
            if(board[x][y-1] == word[layer]){
                Search(board, word, layer+1, route, x, y-1, n, m, found);
            }
        }
        if(found){
            return;
        }
        if(y < m-1 && route.find(x*m+y+1) == route.end()){
            if(board[x][y+1] == word[layer]){
                Search(board, word, layer+1, route, x, y+1, n, m, found);
            }
        }
        if(found){
            return;
        }
        route.erase(x*m+y);
    }
    
    
    bool exist(vector<vector<char>>& board, string word) {
        bool found = false;;
        unordered_set<int> route;
        int n = board.size();
        int m = board[0].size();
        unordered_set<char> chars;
        for(int i=0; i<word.length(); i++){
            chars.insert(word[i]);
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                chars.erase(board[i][j]);
            }
        }
        if(chars.size() != 0){
            return false;
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == word[0]){
                    Search(board, word, 1, route, i, j, n, m, found);
                    if(found){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};