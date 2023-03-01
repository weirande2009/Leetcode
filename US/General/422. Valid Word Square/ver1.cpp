#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        int m = words.size();
        int n = 0;
        for(int i=0; i<m; i++){
            n = max(n, (int)words[i].length());
        }
        if(n != m){
            return false;
        }
        for(int i=0; i<m-1; i++){
            for(int j=i+1; j<n; j++){
                if(j >= words[i].length() && i >= words[j].length()){
                    break;
                }
                else if(j >= words[i].length() || i >= words[j].length()){
                    return false;
                }
                if(words[i][j] != words[j][i]){
                    return false;
                }
            }
        }
        return true;
    }
};