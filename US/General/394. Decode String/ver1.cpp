#include <string>
using namespace std;

// Algorithm: Use a recursion to decode the string when facing '['

class Solution {
public:
    
    string decodeBracket(const string& s, int start, int n, int &end){
        string r;
        for(int i=start; i<n; i++){
            if(s[i] >= 'a' && s[i] <= 'z'){
                r += s[i];
            }
            else if(s[i] >= '0' && s[i] <= '9'){
                int count = 0;
                while(s[i] != '['){
                    count = count*10 + s[i] - '0';
                    i++;
                }
                int end;
                string tmp = decodeBracket(s, i+1, n, end);
                for(int j=0; j<count; j++){
                    r += tmp;
                }
                i = end;
            }
            else if(s[i] == ']'){
                end = i;
                break;
            }
        }
        return r;
    }
    
    string decodeString(string s) {
        string r;
        int n = s.length();
        int count = 0;
        for(int i=0; i<n; i++){
            if(s[i] >= 'a' && s[i] <= 'z'){
                r += s[i];
            }
            else if(s[i] >= '0' && s[i] <= '9'){
                count = count*10+s[i]-'0';
            }
            else if(s[i] == '['){
                int end;
                string tmp = decodeBracket(s, i+1, n, end);
                for(int j=0; j<count; j++){
                    r += tmp;
                }
                i = end;
                count = 0;
            }
        }
        return r;        
    }
};