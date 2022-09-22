#include <string>
using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        int i = 0;
        int n = s.length();
        // Space
        while(s[i] == ' '){
            i++;
            if(i >= n){
                return false;
            }
        }
        if(i >= n){
            return false;
        }
        // Whether + or -
        if(s[i] == '+' || s[i] == '-'){
            i++;
        }
        if(i >= n){
            return false;
        }
        // Find a number
        bool num_before_dot = false;
        while(s[i] >= '0' && s[i] <= '9'){
            i++;
            num_before_dot = true;
            if(i >= n){
                return true;
            }
        }
        // Whether is '.'
        if(s[i] == '.'){
            i++;
        }
        if(i >= n){
            return num_before_dot;
        }
        bool num_after_dot = false;
        while(s[i] >= '0' && s[i] <= '9'){
            i++;
            num_after_dot = true;
            if(i >= n){
                return true;
            }
        }
        // Whether is 'e' or 'E'
        bool has_e = false;
        if((s[i] == 'e' || s[i] == 'E') && (num_before_dot || num_after_dot)){
            i++;
            has_e = true;
        }
        if(i >= n){
            return !has_e;
        }
        bool has_e_num = false;
        if(has_e){
            if(s[i] == '+' || s[i] == '-'){
                i++;
            }
            if(i >= n){
                return false;
            }
            while(s[i] >= '0' && s[i] <= '9'){
                i++;
                has_e_num = true;
                if(i >= n){
                    return true;
                }
            }
        }
        // Space
        while(s[i] == ' '){
            i++;
            if(i >= n){
                return (num_before_dot || num_after_dot) && (!has_e || has_e_num);
            }
        }
        return false;
    }
};


int main(){
    Solution s;
    s.isNumber("-1.e49046 ");
}