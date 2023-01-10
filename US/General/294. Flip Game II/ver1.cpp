#include <string>
using namespace std;

class Solution {
public:
    bool dfs(string& currentState){
        int n = currentState.length();
        for(int i=1; i<n; i++){
            if(currentState[i-1] == '+' && currentState[i] == '+'){
                currentState[i-1] = '-';
                currentState[i] = '-';
                if(!dfs(currentState)){
                    currentState[i-1] = '+';
                    currentState[i] = '+';
                    return true;
                }
                currentState[i-1] = '+';
                currentState[i] = '+';
            }
        }
        return false;
    }

    bool canWin(string currentState) {
        int n = currentState.length();
        return dfs(currentState);
    }
};
