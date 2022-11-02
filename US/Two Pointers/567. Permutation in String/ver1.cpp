#include <string>
#include <unordered_map>
using namespace std;



class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> hashtable;
        int s1_l = s1.length();
        int s2_l = s2.length();
        for(int i=0; i<s1_l; i++){
            if(s1[i] < 'a' || s1[i] > 'z'){
                s1_l--;
                continue;
            }
            if(hashtable.find(s1[i]) == hashtable.end()){
                hashtable[s1[i]] = 1;
            }
            else{
                hashtable[s1[i]]++;
            }
        }
        int next_in_s1 = -1;
        int cur_first_index = -1;
        bool in_s1 = false;
        for(int i=0; i<s2_l; i++){
            if(!in_s1){
                if(hashtable.find(s2[i]) != hashtable.end()){
                    in_s1 = true;
                    cur_first_index = i;
                    hashtable[s2[i]]--;
                    if(i-cur_first_index+1 == s1_l){
                        return true;
                    }
                }
                else{
                    
                }
            }
            else{
                if(hashtable.find(s2[i]) != hashtable.end()){
                    if(hashtable[s2[i]] > 0){
                        hashtable[s2[i]]--;
                        if(i-cur_first_index+1 == s1_l){
                            return true;
                        }
                    }
                    else{
                        // recover and set the next start
                        for(int j=cur_first_index; j<i; j++){
                            if(s2[j] == s2[i]){
                                cur_first_index = j+1;
                                break;
                            }
                            hashtable[s2[j]]++;
                        }
                    }
                }
                else{
                    // recover all
                    for(int j=cur_first_index; j<i; j++){
                        hashtable[s2[j]]++;
                    }
                    in_s1 = false;
                }
            }
        }
        return false;
    }
};