#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int n = tokens.size();
        int score = 0;
        int ans = 0;
        int i = 0;
        int j = n-1;
        while(i <= j){
            if(power >= tokens[i]){
                score++;
                power -= tokens[i];
                i++;
            }
            else{
                if(score >= 1){
                    power += tokens[j];
                    score--;
                    j--;
                }
                else{
                    break;
                }
            }
            ans = max(ans, score);
        }
        return ans;
    }
};