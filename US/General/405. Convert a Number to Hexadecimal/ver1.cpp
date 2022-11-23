#include <unordered_map>
#include <limits.h>
using namespace std;

class Solution {
public:
    string toHex(int num) {
        bool neg = false;
        if(num < 0){
            neg = true;
        }
        if(num == 0){
            return "0";
        }
        unsigned int n = abs(num);
        if(neg){
            n = UINT_MAX - n + 1;
        }
        unordered_map<int, char> hashtable;
        hashtable[0] = '0';
        hashtable[1] = '1';
        hashtable[2] = '2';
        hashtable[3] = '3';
        hashtable[4] = '4';
        hashtable[5] = '5';
        hashtable[6] = '6';
        hashtable[7] = '7';
        hashtable[8] = '8';
        hashtable[9] = '9';
        hashtable[10] = 'a';
        hashtable[11] = 'b';
        hashtable[12] = 'c';
        hashtable[13] = 'd';
        hashtable[14] = 'e';
        hashtable[15] = 'f';
        string result;
        while(n > 0){
            result = hashtable[n%16] + result;
            n /= 16;
        }
        return result;
        
        
    }
};