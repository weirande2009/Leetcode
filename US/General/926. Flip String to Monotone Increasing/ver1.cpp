#include <vector>
#include <string>
#include <limits.h>
using namespace std;

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.length();
        vector<vector<int>> record(n+1, {0, 0});
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
        record[0] = {0, zero_num};
        record[n] = {one_num, 0};
        int ans = min(zero_num, one_num);
        for(int i=1; i<n; i++){
            if(s[i-1] == '1'){
                record[i] = {record[i-1][0]+1, record[i-1][1]};
            }
            else{
                record[i] = {record[i-1][0], record[i-1][1]-1};
            }
            ans = min(ans, record[i][0]+record[i][1]);
        }
        return ans;
    }
};