#include <vector>
using namespace std;


class Solution {
public:
    int dfs(int n){
        if(n == 1){
            return 0;
        }
        int result;
        if(n % 2 == 0){  // even
            result = dfs(n/2) + 1;
        }
        else{
            result = min(dfs(n-1), dfs(n/2+1)+1) + 1;
        }
        return result;
    }

    int integerReplacement(int n) {
        return dfs(n);
    }
};