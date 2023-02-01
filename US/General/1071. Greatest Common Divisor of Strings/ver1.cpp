#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool divisable(const string& s, const string& d){
        if(s.length() % d.length() != 0){
            return false;
        }
        for(int i=0; i<s.length(); i+=d.length()){
            if(s.substr(i, d.length()) != d){
                return false;
            }
        }
        return true;
    }

    string gcdOfStrings(string str1, string str2) {
        string s;
        for(int i=0; i<str1.length(); i++){
            s += str1[i];
            if(divisable(str1, s)){
                break;
            }
        }
        int times_str1 = str1.length() / s.length();
        if(!divisable(str2, s)){
            return "";
        }
        int times_str2 = str2.length() / s.length();
        int end = min(times_str2, times_str1);
        int times = 0;
        for(int i=1; i<=end; i++){
            if(times_str1 % i == 0 && times_str2 % i == 0){
                times = i;
            }
        }
        string ans;
        for(int i=0; i<times; i++){
            ans.append(s);
        }
        return ans;
    }
};