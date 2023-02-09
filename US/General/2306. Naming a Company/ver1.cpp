#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        vector<unordered_set<string>> hashtables(26);
        for(auto& s: ideas){
            if(s.length() > 1){
                hashtables[s[0]-'a'].insert(s.substr(1));
            }
            else{
                hashtables[s[0]-'a'].insert("");
            }
        }

        long long count = 0;
        for(int i=0; i<26; i++){
            for(int j=i+1; j<26; j++){
                int same = 0;
                for(auto& s: hashtables[i]){
                    if(hashtables[j].find(s) != hashtables[j].end()){
                        // find the number of same
                        same++;
                    }
                }
                // we can have any combination of i and j without same suffix
                count += 2*(hashtables[i].size()-same)*(hashtables[j].size()-same);
            }
        }
        return count;
    }
};