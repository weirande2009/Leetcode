#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {

public:
    bool dfs(vector<int>& matchsticks, vector<int>& lens, int no, int n, int target){
        if(no == n){
            return lens[0] == lens[1] && lens[1] == lens[2] && lens[2] == lens[3];
        }
        for(int i=0; i<4; i++){
            if(lens[i] + matchsticks[no] <= target){
                lens[i] += matchsticks[no];
                if(dfs(matchsticks, lens, no+1, n, target)){
                    return true;
                }
                lens[i] -= matchsticks[no];
            }
        }
        return false;
    }

    bool makesquare(vector<int>& matchsticks) {
        int n = matchsticks.size();
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if(sum % 4 != 0){
            return false;
        }
        // sort the arr in reverse order
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        vector<int> lens(4, 0);
        return dfs(matchsticks, lens, 0, n, sum/4);
    }
};