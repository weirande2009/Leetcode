#include <string>
#include <unordered_map>
using namespace std;


class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> hashtable;
        for(char c: magazine){
            hashtable[c]++;
        }
        
        for(char c: ransomNote){
            if(hashtable.find(c) != hashtable.end()){
                if(hashtable[c] > 0){
                    hashtable[c]--;
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
        return true;
    }
};