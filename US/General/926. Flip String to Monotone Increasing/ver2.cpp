#include <vector>
#include <string>
#include <limits.h>
using namespace std;

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.length();
        int zero_num = 0;
        int one_num = 0;
        for(int i=0; i<n; i++){
            if(s[i] == '0'){
                zero_num++;
            }
            else{
                one_num++;
            }
        }
        int ans = min(zero_num, one_num);
        one_num = 0;
        for(int i=1; i<n; i++){
            if(s[i-1] == '1'){
                // current one number in the left increase
                one_num++;
            }
            else{
                // current zero number in the right decrease
                zero_num--;
            }
            ans = min(ans, one_num+zero_num);
        }
        return ans;
    }
};
