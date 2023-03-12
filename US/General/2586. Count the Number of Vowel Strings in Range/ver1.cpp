#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int vowelStrings(vector<string>& words, int left, int right) {
        int count = 0;
        unordered_set<char> hashtable;
        hashtable.insert('a');
        hashtable.insert('e');
        hashtable.insert('i');
        hashtable.insert('o');
        hashtable.insert('u');
        for(int i=left; i<=right; i++){
            if(hashtable.find(words[i][0]) != hashtable.end() && hashtable.find(words[i].back()) != hashtable.end()){
                count++;
            }
        }
        return count;
    }
};