#include <string>
#include <unordered_map>
using namespace std;

// Algorithm: Use unordered_map to record the number of each character in s. Then check
// whether there is the same number of each character in t.

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<int, int> hashtable;
        int l_s = s.length();
        int l_t = t.length();
        if(l_s != l_t){
            return false;
        }
        for(int i=0; i<l_s; i++){
            auto f = hashtable.find(s[i]);
            if(f == hashtable.end()){
                hashtable[s[i]] = 1;
            }
            else{
                hashtable[s[i]]++;
            }
        }
        for(int i=0; i<l_t; i++){
            auto f = hashtable.find(t[i]);
            if(f == hashtable.end()){
                return false;
            }
            else{
                hashtable[t[i]]--;
            }
        }
        for(auto h: hashtable){
            if(h.second != 0){
                return false;
            }
        }
        return true;
    }
};