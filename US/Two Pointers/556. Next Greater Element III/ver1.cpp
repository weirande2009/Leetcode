#include <string>
#include <limits.h>
#include <algorithm>
using namespace std;


class Solution {
public:
    bool myStrings1largerthans2(const string& s1, const string& s2){
        if(s1.length() != s2.length()){
            return s1.length() > s2.length();
        }
        for(int i=0; i<s1.length(); i++){
            if(s1[i] != s2[i]){
                return s1[i] > s2[i];
            }
        }
        return false;
    }
    
    int nextGreaterElement(int n) {
        string s = to_string(n);
        int l = s.length();
        int pivot = -1;
        // find first s[i] > s[i-1]
        for(int i=l-1; i>=1; i--){
            if(s[i] > s[i-1]){
                pivot = i;
                break;
            }
        }
        if(pivot == -1){
            return -1;
        }
        // swap smallest number after pivot which are bigger than s[pivot-1]
        char min_num = '9'+1;
        int index = 0;
        for(int i=pivot; i<l; i++){
            if(s[i] > s[pivot-1]){
                if(s[i] < min_num){
                    min_num = s[i];
                    index = i;
                }
            }
        }
        int tmp = s[index];
        s[index] = s[pivot-1];
        s[pivot-1] = tmp;
        sort(s.begin()+pivot, s.end());
        // check overflow
        string m = to_string(INT_MAX);
        if(myStrings1largerthans2(s, m)){
            return -1;
        }
        else{
            return stoi(s);
        }
    }
};