#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length() != t.length()){
            return false;
        }
        int n = s.length();
        unordered_map<char, char> hashtable;
        for(int i=0; i<n; i++){
            if(hashtable.find(t[i]) != hashtable.end()){
                if(hashtable[t[i]] != s[i]){
                    return false;
                }
            }
            else{
                hashtable[t[i]] = s[i];
            }
        }
        hashtable.clear();
        for(int i=0; i<n; i++){
            if(hashtable.find(s[i]) != hashtable.end()){
                if(hashtable[s[i]] != t[i]){
                    return false;
                }
            }
            else{
                hashtable[s[i]] = t[i];
            }
        }
        return true;
    }
};
