#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        sort(dictionary.begin(), dictionary.end());
        int length = 0;
        int id = -1;
        for(int j=0; j<dictionary.size(); j++){
            if(dictionary[j].length() > s.length()){
                continue;
            }
            if(j == 178){
                int b = 0;
            }
            int i = 0;
            bool found = true;
            for(char c: dictionary[j]){
                bool f = false;
                for(; i<s.length(); i++){
                    if(s[i] == c){
                        f = true;
                        i++;
                        break;
                    }
                }
                if(!f){
                    found = false;
                    break;
                }
            }
            if(found){
                if(dictionary[j].length() > length){
                    length = dictionary[j].length();
                    id = j;
                }
            }
        }
        return id == -1 ? "" : dictionary[id];
    }
};