#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string>> dfs(const string& s, int pos, vector<vector<vector<string>>>& memo, vector<vector<bool>>& dp){
        if(pos >= s.length()){
            return {{}};
        }
        if(memo[pos].size() != 0){
            return memo[pos];
        }
        vector<vector<string>> ans;
        for(int i=0; i<dp.size()-pos; i++){
            if(dp[i][pos]){
                string subs = s.substr(pos, i+1);
                vector<vector<string>> tmp = dfs(s, pos+i+1, memo, dp);
                for(auto& v: tmp){
                    ans.push_back({subs});
                    ans[ans.size()-1].insert(ans[ans.size()-1].end(), v.begin(), v.end());
                }
            }
        }
        memo[pos] = ans;
        return ans;
    }

    vector<vector<string>> partition(string s) {
        int n = s.length();
        // dp[i][j] means whether the substring of start in j and length of i+1 is a palindrome
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        vector<vector<string>> ans;
        for(int i=0; i<n; i++){
            dp[0][i] = true;
        }
        for(int i=1; i<n; i++){
            for(int j=0; j<n; j++){
                int k = j+i;
                if(k >= n){
                    break;
                }
                if(i < 3){
                    dp[i][j] = s[j] == s[k];
                }
                else{
                    dp[i][j] = s[j] == s[k] && dp[i-2][j+1];
                }
            }
        }
        vector<vector<vector<string>>> memo(n);
        return dfs(s, 0, memo, dp);
    }
};