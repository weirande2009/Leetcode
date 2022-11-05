#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    void dfs(const string digits, unordered_map<char, string>& hashtable, vector<string>& result, int layer, string cur){
        if(cur.length() == digits.length()){
            result.push_back(cur);
            return;
        }
        for(int i=0; i<hashtable[digits[layer]].length(); i++){
            dfs(digits, hashtable, result, layer+1, cur+hashtable[digits[layer]][i]);
        }
    }
    
    
    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0){
            return {};
        }
        unordered_map<char, string> hashtable;
        hashtable['2'] = "abc";
        hashtable['3'] = "def";
        hashtable['4'] = "ghi";
        hashtable['5'] = "jkl";
        hashtable['6'] = "mno";
        hashtable['7'] = "pqrs";
        hashtable['8'] = "tuv";
        hashtable['9'] = "wxyz";
        vector<string> result;
        dfs(digits, hashtable, result, 0, "");
        return result;
    }
};