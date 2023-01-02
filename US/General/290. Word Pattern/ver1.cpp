#include <unordered_map>
using namespace std;


class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<string, char> hashtable;
        int begin = 0;
        string pat;
        s += ' ';
        for(int i=0; i<s.length(); i++){
            if(s[i] == ' '){
                string t = s.substr(begin, i-begin);
                if(hashtable.find(t) == hashtable.end()){
                    hashtable[t] = hashtable.size()+'a';
                }
                pat += hashtable[t];
                begin = i+1;
            }
        }
        unordered_map<char, char> ht;
        string p;
        for(int i=0; i<pattern.length(); i++){
            if(ht.find(pattern[i]) == ht.end()){
                ht[pattern[i]] = ht.size()+'a';
            }
            p += ht[pattern[i]];
        }

        return pat == p;
    }
};