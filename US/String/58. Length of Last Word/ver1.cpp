#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        int length = 0;
        bool begin = false;
        for(int i=0; i<n; i++){
            if(s[n-i-1] == ' '){
                if(begin){
                    break;
                }
            }
            else{
                begin = true;
            }
            if(begin){
                length++;
            }
        }
        return length;
    }
};

int main(){
    string str = "   fly me   to   the moon  ";
    Solution s;
    s.lengthOfLastWord(str);

    return 0;
}
