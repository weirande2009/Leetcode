#include <unordered_map>
#include <vector>
using namespace std;

// Algorithm: Use recursion, like depth-first traverse

class Solution {
private:
    unordered_map<char, string> m;
    bool initialized = false;
    
public:
    void Initialize(){
        m['2'] = "abc";
        m['3'] = "def";
        m['4'] = "ghi";
        m['5'] = "jkl";
        m['6'] = "mno";
        m['7'] = "pqrs";
        m['8'] = "tuv";
        m['9'] = "wxyz";
    }
    
    void Recursion(const string& digits, vector<string>& result, int layer, string pre_str){
        if(layer == digits.size()){
            result.push_back(pre_str);
            return;
        }
        for(int i=0; i<m[digits[layer]].length(); i++){
            string s = pre_str + m[digits[layer]][i];
            Recursion(digits, result, layer+1, s);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0){
            return {};
        }
        vector<string> result;
        if(!initialized){
            Initialize();
            initialized = true;
        }
        Recursion(digits, result, 0, "");
        return result;
    }
};