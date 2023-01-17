#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.length();
        while(1){
            bool changed = false;
            for(int i=0; i<n; i++){
                if(dominoes[i] == 'L'){
                    if(i != 0){
                        if(dominoes[i-1] == '.'){
                            dominoes[i-1] = 'L'+1;
                        }
                        else if(dominoes[i-1] == 'R'+1){
                            dominoes[i-1] = '.';
                        }
                    }
                }
                else if(dominoes[i] == 'R'){
                    if(i != n-1){
                        if(dominoes[i+1] == '.'){
                            dominoes[i+1] = 'R'+1;
                        }
                    }
                }
            }
            for(int i=0; i<n; i++){
                if(dominoes[i] == 'L'+1 || dominoes[i] == 'R'+1){
                    dominoes[i] -= 1;
                    changed = true;
                }
            }
            if(!changed){
                break;
            }
        }
        return dominoes;
    }
};