#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int count = 0;
        int l = strs[0].length();
        for(int i=0; i<l; i++){
            for(int j=1; j<strs.size(); j++){
                if(strs[j][i] < strs[j-1][i]){
                    count++;
                    break;
                }
            }
        }
        return count;
    }
};
