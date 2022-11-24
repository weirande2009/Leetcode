#include <string>
using namespace std;


class Solution {
public:
    string addBinary(string a, string b) {
        int l1 = a.length();
        if(a[l1-1] == '\"'){
            a.erase(a.begin()+l1-1);
            l1--;
        }
        int l2 = b.length();
        if(l2 > l1){
            string tmp = a;
            a = b;
            b = tmp;
            int t = l1;
            l1 = l2;
            l2 = t;
        }
        int carry = 0;
        for(int i=0; i<l2; i++){
            a[l1-1-i] += b[l2-1-i]-'0'+carry;
            if(a[l1-1-i] >= '2'){
                a[l1-1-i] -= 2;
                carry = 1;
            }
            else{
                carry = 0;
            }
        }
        if(carry == 1){
            for(int i=l1-l2-1; i>=0; i--){
                a[i] += carry;
                if(a[i] >= '2'){
                    a[i] -= 2;
                    carry = 1;
                }
                else{
                    carry = 0;
                }
            }
            if(carry == 1){
                a = "1" + a;
            }
        }
        return a;
        
        
    }
};