#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        // sort the words by length
        sort(words.begin(), words.end(), [](const string& s1, const string& s2){
            return s1.length() < s2.length();
        });
        int n = words.size();
        // dp[i] means the length of chain until words[i]
        vector<int> dp(n, 1);
        int last_length = words[0].length();
        // find the next length
        int start = 0;
        int last_start = 0;
        for(int i=1; i<n; i++){
            if(words[i].length() != last_length){
                start = i;
                break;
            }
        }
        int ans = 1;
        for(int i=start; i<n; i++){
            if(words[i].length() == words[start].length()){
                int l = words[i].length();
                if(words[i].length() == words[last_start].length()+1){
                    for(int j=last_start; j<start; j++){
                        int m = 0;
                        int n = 0;
                        int dif_times = 0;
                        while(m < l || n < l-1){
                            if(words[i][m] == words[j][n]){
                                m++;
                                n++;
                            }
                            else{
                                dif_times++;
                                m++;
                                if(dif_times > 1){
                                    break;
                                }
                            }
                        }
                        if(dif_times <= 1){
                            dp[i] = max(dp[i], dp[j]+1);
                        }
                    }
                }
            }
            else{
                last_start = start;
                start = i;
                i--;
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};