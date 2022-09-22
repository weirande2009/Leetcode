#include <iostream>
#include <string>
using namespace std;

// "abcabcbb"

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string pre_sub;
        int max_length = 0;
        int pre_length = 0;
        int begin_index = 0;
        for(int i=0; i<s.length(); i++){
            int pos = pre_sub.find(s[i]);
            if(pos == string::npos){  // if there is no, add to tail
                pre_sub += s[i];
                pre_length++;
            }
            else{  // if there is, record pre sub if it's longest, and then find the next
                if(max_length < pre_length){
                    max_length = pre_length;
                }
                pre_sub = pre_sub.substr(pos+1);
                pre_sub += s[i];
                pre_length = pre_length - (pos + 1) + 1;
            }
        }
        if(max_length < pre_length){
            max_length = pre_length;
        }
        return max_length;
    }
};

int main(){
    Solution s;
    int l = s.lengthOfLongestSubstring("ggububgvfk");
    cout << l << endl;
}