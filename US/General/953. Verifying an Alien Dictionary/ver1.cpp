#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool comeBefore(unordered_map<char, int>& hashtable, const string& s1, const string& s2){
        int end = min(s1.length(), s2.length());
        for(int i=0; i<end; i++){
            if(hashtable[s1[i]] > hashtable[s2[i]]){
                return false;
            }
            else if(hashtable[s1[i]] < hashtable[s2[i]]){
                return true;
            }
        }
        return s1.length() <= s2.length();
    }

    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> hashtable;
        for(int i=0; i<order.length(); i++){
            hashtable[order[i]] = i;
        }
        for(int i=1; i<words.size(); i++){
            if(!comeBefore(hashtable, words[i-1], words[i])){
                return false;
            }
        }
        return true;
    }
};