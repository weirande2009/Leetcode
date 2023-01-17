#include <string>
using namespace std;

class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.length();
        for(int i=0; i<n; i++){
            if(dominoes[i] == 'L'){
                // push down all left straight
                for(int j=i-1; j>=0; j--){
                    if(dominoes[j] == '.'){
                        dominoes[j] = 'L';
                    }
                    else{
                        break;
                    }
                }
            }
            else if(dominoes[i] == 'R'){
                // find the next left
                int pos = -1;
                for(int j=i+1; j<n; j++){
                    if(dominoes[j] == 'L'){
                        pos = j;
                        break;
                    }
                    else if(dominoes[j] == 'R'){
                        // just push down all right
                        for(int k=i+1; k<j; k++){
                            dominoes[k] = 'R';
                        }
                        // update index
                        i = j-1;
                        pos = -2;
                        break;
                    }
                }
                if(pos == -2){
                    continue;
                }
                else if(pos == -1){
                    for(i++; i<n; i++){
                        dominoes[i] = 'R';
                    }
                }
                else{
                    int left = i+1;
                    int right = pos-1;
                    while(left < right){
                        dominoes[left++] = 'R';
                        dominoes[right--] = 'L';
                    }
                    // update index
                    i = pos;
                }
            }
        }
        return dominoes;
    }
};