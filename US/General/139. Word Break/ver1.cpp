#include <vector>
#include <string>
#include <algorithm>
using namespace std;


class Solution {
public:
    bool dfs(string& s, vector<string>& wordDict, vector<int>& memo, int i, int l){
        if(i == l){
            return true;
        }
        if(memo[i] != -1){
            return memo[i];
        }
        for(string word: wordDict){
            if(word.length() > l-i){
                break;
            }
            if(s.substr(i, word.length()) == word){
                if(dfs(s, wordDict, memo, i+word.length(), l)){
                    memo[i] = 1;
                    return memo[i];
                }
            }
        }
        memo[i] = 0;
        return memo[i];
    }
    
    
    bool wordBreak(string s, vector<string>& wordDict) {
        int l = s.length();
        sort(wordDict.begin(), wordDict.end(), [](const string& s1, const string& s2){
            return s1.length() < s2.length();
        });
        // memo[i] means whether it's possible to segment s[i:]
        vector<int> memo(l, -1);
        return dfs(s, wordDict, memo, 0, l);
    }
};