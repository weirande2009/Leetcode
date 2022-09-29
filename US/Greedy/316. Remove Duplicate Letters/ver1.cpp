#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> alphabet(26, 0);
        int n = s.length();
        // Count each char's number in s
        for(int i=0; i<n; i++){
            alphabet[s[i]-'a']++;
        }
        // Record the lowest character whose suffix contain all the characters
        int pos = 0;
        for(int i=0; i<n; i++){
            if(s[i] < s[pos]){
                pos = i;
            }
            alphabet[s[i]-'a']--;
            if(alphabet[s[i]-'a'] == 0){
                break;
            }
        }
        // Build the left string without s[pos] for recursion
        string result;
        for(int i=pos+1; i<n; i++){
            if(s[i] != s[pos]){
                result += s[i];
            }
        }
        
        return s.length() == 0 ? "" : s[pos]+removeDuplicateLetters(result);
    }
};