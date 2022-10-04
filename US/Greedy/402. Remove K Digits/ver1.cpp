#include <vector>
#include <string>
using namespace std;

// Algorithm: Find k num[i] such that num[i+1] > num[i] in the removed string.. 



class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<bool> removed(num.length(), false);
        int current_removed_num = 0;
        int j = 0;
        
        for(int i=1; i<num.length(); i++){
            if(num[i] < num[j]){
                removed[j] = true;
                bool found = false;
                for(int l=j; l>=0; l--){
                    if(!removed[l]){
                        j = l;
                        found = true;
                        break;
                    }
                }
                if(found){
                    i--;
                }
                else{
                    j = i;
                }
                current_removed_num++;
            }
            else{
                j = i;
            }
            if(current_removed_num == k){
                break;
            }
        }
        for(int i=0; i<k-current_removed_num; i++){
            removed[num.length()-i-1] = true;
        }
        string s;
        for(int i=0; i<num.length(); i++){
            if(!removed[i]){
                if(s.length() != 0 || num[i] != '0'){
                    s += num[i];
                }
            }
        }
        if(s.length() == 0){
            return "0";
        }
        return s.substr(0, num.length()-k);
    }
};