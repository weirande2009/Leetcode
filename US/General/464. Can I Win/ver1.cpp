#include <vector>
using namespace std;

class Solution {
public:
    bool dfs(int maxChoosableInteger, int desiredTotal, vector<int>& memo, int state){
        // when the player before has make the result to 0, loss
        if(desiredTotal <= 0){
            return false;
        }
        // we've meet this state before
        if(memo[state] != 0){
            return memo[state] == 1;
        }
        // iterate all possible choice
        for(int i=0; i<maxChoosableInteger; i++){
            // if the i-th number is available and our opponent loses all cases
            if(!(state&(1<<i)) && !dfs(maxChoosableInteger, desiredTotal-i-1, memo, state|(1<<i))){
                memo[state] = 1;
                return true;
            }
        }
        // if we fail to win in all choice, we loss
        memo[state] = -1;
        return false;
    }

    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if(maxChoosableInteger >= desiredTotal){
            return true;
        }
        int sum = maxChoosableInteger * (maxChoosableInteger+1) / 2;
        if(sum < desiredTotal){
            return false;
        }
        vector<int> memo(1<<20, 0);
        return dfs(maxChoosableInteger, desiredTotal, memo, 0);
    }
};