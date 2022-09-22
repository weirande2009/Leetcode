#include <vector>
#include <string>
using namespace std;

// Algorithm: Separate the problem into add, multiply by m(a number <= 9) and addByOne

class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1.length() == 1 && num1[0] == '0'){
            return "0";
        }
        if(num2.length() == 1 && num2[0] == '0'){
            return "0";
        }
        string result = "0";
        int n1 = num1.length();
        for(int i=0; i<n1; i++){
            string r = multiplyByOne(num2, num1[n1-i-1]-'0');
            for(int j=0; j<i; j++){
                r += '0';
            }
            result = add(result, r);
        }
        return result;
    }
    
    string add(string num1, string num2){
        string result;
        int i = 0;
        int n1 = num1.length();
        int n2 = num2.length();
        int carry = 0;
        while(1){
            if(i >= n1 && i >= n2){  // num1 and num2 end
                if(carry){
                    result = "1" + result;
                }
                break;
            }
            else if(i >= n1){  // num1 end
                if(carry){
                    string left = addOne(num2.substr(0, n2-i));
                    result = left + result;
                }
                else{
                    result = num2.substr(0, n2-i) + result;
                }
                break;
            }
            else if(i >= n2){
                if(carry){
                    string left = addOne(num1.substr(0, n1-i));
                    result = left + result;
                }
                else{
                    result = num1.substr(0, n1-i) + result;
                }
                break;
            }
            else{
                char c = num1[n1-i-1] - '0'+ num2[n2-i-1] + carry;
                if(c > '9'){
                    c -= 10;
                    carry = 1;
                }
                else{
                    carry = 0;
                }
                string tmp;
                tmp += c;
                result = tmp + result;
            }
            i++;
        }
        return result;
    }
    
    string addOne(string num){
        string result;
        int n = num.length();
        int carry = 1;
        for(int i=0; i<n; i++){
            char c = num[n-i-1] + carry;
            if(c > '9'){
                c -= 10;
                carry = 1;
            }
            else{
                carry = 0;
            }
            string tmp;
            tmp += c;
            result = tmp + result;
        }
        if(carry){
            result = "1" + result;
        }
        return result;
    }
    
    string multiplyByOne(string num, int m){
        string result;
        int n = num.length();
        int carry = 0;
        for(int i=0; i<n; i++){
            int mul = (num[n-i-1] - '0') * m + carry;
            carry = mul / 10;
            char c = mul % 10 + '0';
            string tmp;
            tmp += c;
            result = tmp + result;
        }
        if(carry){
            char c = '0' + carry;
            string tmp;
            tmp += c;
            result = tmp + result;
        }
        return result;
    }
};

int main(){
    string num1 = "81";
    string num2 = "7314";
    Solution s;
    s.multiply(num1, num2);


    return 0;

}

