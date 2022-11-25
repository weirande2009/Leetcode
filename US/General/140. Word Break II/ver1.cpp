#include <string>
#include <vector>
using namespace std;


class Solution {
public:
    void dfs(vector<string>& result, string& s, vector<string>& wordDict, vector<string>& cur_lists, int i, int l){
        if(i == l){
            string tmp = cur_lists[0];
            for(int i=1; i<cur_lists.size(); i++){
                tmp += " ";
                tmp += cur_lists[i];
            }
            result.push_back(tmp);
        }
        for(string word: wordDict){
            if(s.substr(i, word.length()) == word){
                cur_lists.push_back(word);
                dfs(result, s, wordDict, cur_lists, i+word.length(), l);
                cur_lists.erase(cur_lists.begin()+cur_lists.size()-1);
            }
        }
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> result;
        vector<string> cur_lists;
        dfs(result, s, wordDict, cur_lists, 0, s.length());
        return result;
    }
};