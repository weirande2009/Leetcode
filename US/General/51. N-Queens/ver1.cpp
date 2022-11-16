#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    void SetAttack(vector<vector<int>>& attack, int row, int col, int n){
        for(int i=0; i<n; i++){
            attack[row][i]++;
            attack[i][col]++;
        }
        for(int i=0; i<n; i++){
            if(row+i+1 < n && col+i+1 < n){
                attack[row+i+1][col+i+1]++;
            }
            else{
                break;
            }
        }
        for(int i=0; i<n; i++){
            if(row-i-1 >= 0 && col-i-1 >= 0){
                attack[row-i-1][col-i-1]++;
            }
            else{
                break;
            }
        }
        for(int i=0; i<n; i++){
            if(row-i-1 >= 0 && col+i+1 < n){
                attack[row-i-1][col+i+1]++;
            }
            else{
                break;
            }
        }
        for(int i=0; i<n; i++){
            if(row+i+1 < n && col-i-1 >= 0){
                attack[row+i+1][col-i-1]++;
            }
            else{
                break;
            }
        }
    }
    
    void SetUnattack(vector<vector<int>>& attack, int row, int col, int n){
        for(int i=0; i<n; i++){
            attack[row][i]--;
            attack[i][col]--;
        }
        for(int i=0; i<n; i++){
            if(row+i+1 < n && col+i+1 < n){
                attack[row+i+1][col+i+1]--;
            }
            else{
                break;
            }
        }
        for(int i=0; i<n; i++){
            if(row-i-1 >= 0 && col-i-1 >= 0){
                attack[row-i-1][col-i-1]--;
            }
            else{
                break;
            }
        }
        for(int i=0; i<n; i++){
            if(row-i-1 >= 0 && col+i+1 < n){
                attack[row-i-1][col+i+1]--;
            }
            else{
                break;
            }
        }
        for(int i=0; i<n; i++){
            if(row+i+1 < n && col-i-1 >= 0){
                attack[row+i+1][col-i-1]--;
            }
            else{
                break;
            }
        }
    }
    
    void dfs(vector<vector<string>>& result, vector<string>& cur, vector<vector<int>>& attack, int n, int layer){
        if(layer == n){
            result.push_back(cur);
            return;
        }
        // find a new place for the current queen
        for(int i=0; i<n; i++){
            if(attack[layer][i] == 0){
                SetAttack(attack, layer, i, n);
                cur[layer][i] = 'Q';
                dfs(result, cur, attack, n, layer+1);
                SetUnattack(attack, layer, i, n);
                cur[layer][i] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> cur(n, string(n, '.'));
        vector<vector<int>> attack(n, vector<int>(n, 0));
        dfs(result, cur, attack, n, 0);
        return result;
    }
};
