#include <string>
#include <vector>
using namespace std;


class Solution {
public:
    void dfs(vector<vector<string>>& result, vector<string>& cur, string& s, int start, int end){
        if(start > end){
            result.push_back(cur);
        }
        for(int i=start; i<=end; i++){
            // for every substring end in i, if it's palindromic, keep search the substring left
            if(isPalindrome(s, start, i)){
                cur.push_back(s.substr(start, i-start+1));
                dfs(result, cur, s, i+1, end);
                cur.erase(cur.begin()+cur.size()-1);
            }
        }
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
    
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> cur;
        int n = s.length();
        dfs(result, cur, s, 0, n-1);
        return result;
    }
};