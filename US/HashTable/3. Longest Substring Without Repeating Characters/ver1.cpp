#include <unordered_map>
#include <string>
using namespace std;

// Algorithm: Use hashtable to record the current word in substring. For each character,
// search it in hashtable, if not exist, add it to hashtable.
// If exist, the current size of hashtable is the current length of substring, compare 
// it to max. Then we need to update the hashtable, find the repeated character's index
// and remove all the chars in hashtable which are before this index and change this index
// to the current index.

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> hashtable;
        int n = s.size();
        int max_length = 0;
        int pre_str_begin = 0;
        for(int i=0; i<n; i++){
            auto f = hashtable.find(s[i]);
            if(f == hashtable.end()){
                hashtable[s[i]] = i;
            }
            else{
                int count = hashtable.size();
                if(count > max_length){
                    max_length = count;
                }
                // Set hash table as new
                for(int j=pre_str_begin; j<hashtable[s[i]]; j++){
                    hashtable.erase(s[j]);
                }
                pre_str_begin = hashtable[s[i]] + 1;
                hashtable[s[i]] = i;
            }
        }
        int count = hashtable.size();
        if(count > max_length){
            max_length = count;
        }
        return max_length;
    }
};
