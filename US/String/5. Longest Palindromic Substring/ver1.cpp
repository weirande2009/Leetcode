#include <string>
#include <vector>
using namespace std;



class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for(int i=0; i<n; n++){
            dp[i][i] = true;
        }
        int max_length = 1;
        int begin_pos = 0;
        for(int i=2; i<=n; i++){  // The outer loop is for length
            for(int j=0; j<n; j++){  // j means the start index
                int k = j + i - 1;  // k means the end index
                if(k > n-1){
                    break;
                }
                if(s[j] == s[k]){
                    if(i > 3){
                        dp[j][k] = dp[j+1][k-1];
                    }
                    else{
                        dp[j][k] = true;
                    }
                    
                }
                if(dp[j][k]){
                    if(i > max_length){
                        max_length = i;
                        begin_pos = j;
                    }
                }
            }
        }
        return s.substr(begin_pos, max_length);
    }
};


int main()
{
    string str = "babad";
    Solution s;
    s.longestPalindrome(str);

    return 0;
}