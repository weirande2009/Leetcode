#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    bool detectCapitalUse(string word) {
        bool first_capital = false;
        if(word[0] >= 'A' && word[0] <= 'Z'){
            first_capital = true;
        }
        int n = word.length();
        int capital_num = 0;
        for(int i=1; i<n; i++){
            if(word[i] >= 'A' && word[i] <= 'Z'){
                capital_num++;
            }
        }
        if((capital_num == 0 || capital_num == n-1) && first_capital || !first_capital && capital_num == 0){
            return true;
        }
        else{
            return false;
        }
    }
};