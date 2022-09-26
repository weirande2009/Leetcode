#include <vector>
#include <string>
using namespace std;

// Algorithm: O(n). Use an alphabet which record the number of each character in s and t.

class Solution {
public:
    bool isAnagram(string s, string t) {
        int s_l = s.length();
        int t_l = t.length();
        if(s_l != t_l){
            return false;
        }
        vector<int> alphabet(26, 0);
        
        for(int i=0; i<s_l; i++){
            alphabet[s[i]-'a']++;
            alphabet[t[i]-'a']--;
        }
        for(int i=0; i<26; i++){
            if(alphabet[i] != 0){
                return false;
            }
        }
        return true;
    }
};