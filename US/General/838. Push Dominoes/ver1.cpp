#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string pushDominoes(string dominoes) {
        // 1 means left, 2 means right, negative means just happen, 0 means straight
        int n = dominoes.length();
        vector<int> state(n, 0);
        for(int i=0; i<n; i++){
            if(dominoes[i] == 'R'){
                state[i] = 2;
            }
            else if(dominoes[i] == 'L'){
                state[i] = 1;
            }
            else if(dominoes[i] == '.'){
                state[i] = 0;
            }
        }
        while(1){
            bool changed = false;
            for(int i=0; i<n; i++){
                if(state[i] == 1){
                    if(i != 0){
                        if(state[i-1] == 0){
                            state[i-1] = -1;
                        }
                        else if(state[i-1] == -2){
                            state[i-1] = 0;
                        }
                    }
                }
                else if(state[i] == 2){
                    if(i != n-1){
                        if(state[i+1] == 0){
                            state[i+1] = -2;
                        }
                    }
                }
            }
            for(int i=0; i<n; i++){
                if(state[i] < 0){
                    state[i] *= -1;
                    changed = true;
                }
            }
            if(!changed){
                break;;
            }
        }
        string ans;
        for(int i=0; i<n; i++){
            if(state[i] == 0){
                ans.push_back('.');
            }
            else if(state[i] == 1){
                ans.push_back('L');
            }
            else if(state[i] == 2){
                ans.push_back('R');
            }
        }
        return ans;
    }
};
