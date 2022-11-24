#include <string>
#include <unordered_map>
using namespace std;



class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> hashtable;
        for(char c: s){
            hashtable[c]++;
        }
        
        int count = 0;
        bool one = false;
        for(auto& a: hashtable){
            if(a.second >= 2){
                count += a.second / 2 * 2;
            }
            if(a.second % 2){
                one = true;
            }
        }
        return count + one;
    }
};