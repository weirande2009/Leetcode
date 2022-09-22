#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string longest_palindrome;
        string tmp;
        int pre_palindrome_begin_pos = 0;
        int max_length = 0;
        for(int i=0; i<s.size(); i++){
            for(int j=1; j<=s.size()-i; j++){
                tmp = s.substr(i, j);
                if(isPalindrome(tmp)){
                    if(max_length < j){
                        max_length = j;
                        longest_palindrome = tmp;
                    }
                }
            }
        }
        return longest_palindrome;
    }

    bool isPalindrome(string s){
        for(int i=0; i<s.size()/2; i++){
            if(s[i] != s[s.size()-1-i]){
                return false;
            }
        }
        return true;
    }
};