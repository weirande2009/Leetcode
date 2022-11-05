#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    void dfs(vector<string>& result, string cur, int n, int left, int right){
        if(left == n && right == n){
            result.push_back(cur);
            return;
        }
        if(left < n){
            dfs(result, cur+"(", n, left+1, right);
        }
        if(right < left){
            dfs(result, cur+")", n, left, right+1);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        dfs(result, "", n, 0, 0);
        return result;
    }
};