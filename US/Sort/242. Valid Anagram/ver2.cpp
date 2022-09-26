#include <string>
#include <algorithm>
using namespace std;

// Allgorithm: Use sort.

class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        int s_l = s.length();
        int t_l = t.length();
        if(s_l != t_l){
            return false;
        }
        for(int i=0; i<s_l; i++){
            if(s[i] != t[i]){
                return false;
            }
        }
        return true;
    }
};