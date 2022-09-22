#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        int max_length = 0;
        while(1){
            char common;
            bool all_same = true;
            for(int i=0; i<strs.size(); i++){
                if(max_length >= strs[i].length()){
                    all_same = false;
                    break;
                }
                if(i == 0){
                    common = strs[i][max_length];
                }
                else{
                    if(strs[i][max_length] != common){
                        all_same = false;
                        break;
                    }
                }
            }
            if(!all_same){
                break;
            }
            max_length++;
        }
        return strs[0].substr(0, max_length);
    }
};

