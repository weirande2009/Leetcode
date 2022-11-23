#include <vector>
#include <string>
using namespace std;



class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string s = to_string(n);
        int l = s.length();
        int high = '9';
        int pos = -1;
        // find the last s[i] < s[i-1]
        for(int i=l-1; i>=1; i--){
            if(s[i] < s[i-1]){
                pos = i;
                // decrease every s[i-1], and continue to find the next, 
                // so that the whole string is valid according to the rule
                s[i-1]--;
            }
        }
        if(pos == -1){
            return n;
        }
        else{
            // set all number after the pos to 9
            for(int i=pos; i<l; i++){
                s[i] = '9';
            }
            return stoi(s);
        }
    }
};