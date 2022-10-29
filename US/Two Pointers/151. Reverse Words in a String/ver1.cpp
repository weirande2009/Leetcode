#include <string>
using namespace std;



class Solution {
public:
    string reverseWords(string s) {
        string result;
        int n = s.length();
        int begin = n-1;
        for(int i=n-1; i>=0; i--){
            if(s[i] != ' '){
                begin = i;
                break;
            }
        }
        int end = 0;
        for(int i=0; i<n; i++){
            if(s[i] != ' '){
                end = i;
                break;
            }
        }
        for(int i=begin; i>=end; i--){
            if(s[i] == ' '){
                if(s[begin] != ' '){
                    result += s.substr(i+1, begin-i);
                    result += " ";
                }
                begin = i-1;
            }
        }
        result += s.substr(end, begin-end+1);
        return result;
    }
};