#include <string>
using namespace std;



class Solution {
public:
    bool isSubsequence(string s, string t) {
        int l1 = s.length();
        int l2 = t.length();
        int p = 0;
        if(p == l1){
            return true;
        }
        for(int i=0; i<l2; i++){
            if(t[i] == s[p]){
                p++;
                if(p == l1){
                    return true;
                }
            }
        }
        return false;
    }
};