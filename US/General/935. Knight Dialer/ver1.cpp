#include <vector>
using namespace std;

class Solution {
public:
    bool validPos(int y, int x){
        if(y < 0 || y >= 4 || x < 0 || x >= 3 || y == 3 && (x == 0 || x == 2)){
            return false;
        }
        return true;
    }

    int knightDialer(int n) {
        const int MOD = 1000000007;
        // dp[i][j][k] means the number of numbers of length i+1 and end in (j, k)
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(4, vector<int>(3, 0)));
        vector<vector<int>> directions = {{-2, 1}, {2, 1}, {-1, 2}, {1, 2}, {-2, -1}, {2, -1}, {-1, -2}, {1, -2}};
        for(int i=0; i<4; i++){
            for(int j=0; j<3; j++){
                if(!validPos(i, j)){
                    continue;
                }
                dp[0][i][j] = 1;
            }
        }
        for(int i=1; i<n; i++){
            for(int j=0; j<4; j++){
                for(int k=0; k<3; k++){
                    if(!validPos(j, k)){
                        continue;
                    }
                    for(int l=0; l<8; l++){
                        int row = j+directions[l][0];
                        int col = k+directions[l][1];
                        if(validPos(row, col)){
                            dp[i][j][k] = (dp[i][j][k]+dp[i-1][row][col]) % MOD;
                        }
                    }
                }
            }
        }
        int count = 0;
        for(int i=0; i<4; i++){
            for(int j=0; j<3; j++){
                count = (count+dp[n-1][i][j]) % MOD;
            }
        }
        return count;
    }
};