#include <vector>
#include <string>
#include <unordered_map>
using namespace std;


class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> hashtable;
        // count each char
        int l = p.length();
        for(char c: p){
            hashtable[c] += 1;
        }
        vector<int> result;
        int begin = -1;
        int n = s.length();
        for(int i=0; i<n; i++){
            auto f = hashtable.find(s[i]);
            if(f == hashtable.end()){  // if don't find
                if(begin != -1){
                    // recover all
                    for(int j=begin; j<i; j++){
                        hashtable[s[j]]++;
                    }
                    begin = -1;
                }
            }
            else{
                if(begin != -1){
                    if(hashtable[s[i]] > 0){
                        hashtable[s[i]]--;
                    }
                    else{
                        // there are more than we want, find the last c == s[i] from begin
                        int last_c;
                        for(int j=begin; j<i; j++){
                            if(s[j] == s[i]){
                                last_c = j;
                                break;
                            }
                        }
                        // recover chars before and including last_c.
                        for(int j=begin; j<last_c; j++){
                            hashtable[s[j]]++;
                        }
                        // now the begin is last_c+1
                        begin = last_c + 1;
                    }
                }
                else{
                    begin = i;
                    hashtable[s[i]]--;
                }
            }
            // check whether we've found all
            if(begin != -1){
                if(i-begin+1 == l){
                    result.push_back(begin);
                }
            }
        }
        return result;
    }
};