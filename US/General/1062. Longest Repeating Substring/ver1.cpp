#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hashRepeat(const string& s, int length){
        unordered_set<string> hashtable;
        for(int j=0; j<s.length()-length+1; j++){
            if(hashtable.find(s.substr(j, length)) != hashtable.end()){
                return true;
            }
            hashtable.insert(s.substr(j, length));
        }
        return false;
    }

    int longestRepeatingSubstring(string s) {
        int low = 0;
        int high = s.length();
        while(low <= high){
            int mid = (low+high) / 2;
            if(hashRepeat(s, mid)){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return low-1;
    }
};