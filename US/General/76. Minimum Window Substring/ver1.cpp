#include <vector>
#include <unordered_map>
#include <limits.h>
using namespace std;

// Use sliding window:
// 1. r++ until we get a desirable window.
// 2. contract window by l-- until we get an undesirable window
// 3. back to step 1


class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> hashtable;
        // count each char
        for(char c: t){
            hashtable[c] += 1;
        }
        
        int t_l = hashtable.size();
        int min_begin = -1;
        int min_length = INT_MAX;
        int n = s.length();
        int l = 0;
        int r = 0;
        int form = 0;
        unordered_map<char, int> count;
        while(r < n){
            count[s[r]]++;
            // if the frequency of the current number is equal to the number we want
            if(hashtable.find(s[r]) != hashtable.end()){
                if(count[s[r]] == hashtable[s[r]]){
                    form++;
                }
            }
            // Try to contract the window till it's not desirable
            while(l <= r && form == t_l){
                if(r-l+1 < min_length){
                    min_length = r-l+1;
                    min_begin = l;
                }
                
                // decrease
                count[s[l]]--;
                
                // check desirable
                if(hashtable.find(s[l]) != hashtable.end()){
                    if(count[s[l]] < hashtable[s[l]]){
                        form--;
                    }
                }
                
                // update l
                l++;
            }
            r++;
        }
        if(min_begin == -1){
            return "";
        }
        else{
            return s.substr(min_begin, min_length);
        }
    }
};