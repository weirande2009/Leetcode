#include <string>
using namespace std;

// Algorithm: 

class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        int left = 0;
        int right = n-1;
        while(left < right){
            while(!(s[left] >= 'A' && s[left] <= 'Z' || s[left] >= 'a' && s[left] <= 'z' || s[left] >= '0' && s[left] <= '9')){
                left++;
                if(left > n-1){
                    break;
                }
            }
            while(!(s[right] >= 'A' && s[right] <= 'Z' || s[right] >= 'a' && s[right] <= 'z' || s[right] >= '0' && s[right] <= '9')){
                right--;
                if(right < 0){
                    break;
                }
            }
            if(left >= right){
                break;
            }
            if(s[left] < 'a'){
                s[left] += 'a'-'A';
            }
            if(s[right] < 'a'){
                s[right] += 'a'-'A';
            }
            if(s[left] != s[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
        
    }
};