#include <vector>
#include <string>
#include <limits.h>
using namespace std;


class Solution {
public:
    int dfs(vector<vector<int>>& memo, string& s, int start, int end){
        if(start > end){
            return 0;
        }
        if(memo[start][end] != -1){
            return memo[start][end];
        }
        int mn = INT_MAX;
        for(int i=start; i<=end; i++){
            // for every substring end in i, if it's palindromic, keep search the substring left
            if(isPalindrome(s, start, i)){
                // if the cut is min, record it
                mn = min(mn, dfs(memo, s, i+1, end)+1);
            }
        }
        memo[start][end] = mn;
        return mn;
    }
    
    bool isPalindrome(string& s, int start, int end){
        int left = start;
        int right = end;
        while(left < right){
            if(s[left] == s[right]){
                left++;
                right--;
            }
            else{
                return false;
            }
        }
        return true;
    }
    
    int minCut(string s) {
        int n = s.length();
        // memo[i][j] means the min cut of start=i, end=j
        vector<vector<int>> memo(n, vector<int>(n, -1));
        return dfs(memo, s, 0, n-1)-1;
    }
};