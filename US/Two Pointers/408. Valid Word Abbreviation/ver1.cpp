#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int n = word.length();
        int m = abbr.length();
        bool in_abbr = false;
        int i=0;
        int j=0;
        int count = 0;
        while(j < m && i < n){
            if(abbr[j] >= 'a' && abbr[j] <= 'z'){
                if(abbr[j] == word[i]){
                    in_abbr = false;
                    j++;
                    i++;
                }
                else{
                    return false;
                }
            }
            else{
                if(abbr[j] == '0' || in_abbr){
                    return false;
                }
                count = 0;
                while(abbr[j] >= '0' && abbr[j] <= '9'){
                    count = count*10+abbr[j]-'0';
                    j++;
                }
                in_abbr = true;
                i+=count;
                if(i > n){
                    return false;
                }
            }
        }
        if(i == n && j == m){
            return true;
        }
        else{
            return false;
        }
    }
};