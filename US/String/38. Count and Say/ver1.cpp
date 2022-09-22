#include <string>
using namespace std;

// Algorithm: when facing ith str, count the repeated number one by one and input the number
// and corresponded char to a new string.

class Solution {
public:
    string countAndSay(int n) {
        if(n == 1){
            return "1";
        }
        string pre_str = "1";
        for(int i=2; i<=n; i++){
            string tmp;
            int pre_char_num = 0;
            char pre_char=pre_str[0];
            for(int j=0; j<pre_str.length(); j++){
                if(pre_str[j] == pre_char){
                    pre_char_num++;
                }
                else{
                    char c = '0' + pre_char_num;
                    tmp += c;
                    tmp += pre_char;
                    pre_char_num = 1;
                    pre_char = pre_str[j];
                }
            }
            char c = '0' + pre_char_num;
            tmp += c;
            tmp += pre_char;
            pre_str = tmp;
        }
        return pre_str;
    }
};