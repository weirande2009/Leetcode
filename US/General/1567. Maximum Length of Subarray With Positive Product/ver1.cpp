#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int positive = 0;
        int negative = 0;
        int ans = 0;
        for(int num: nums){
            if(num > 0){
                ans = max(ans, positive+1);
                positive++;
                negative = negative != 0 ? negative+1 : 0;
            }
            else if(num < 0){
                if(negative != 0){
                    ans = max(ans, negative+1);
                }
                int tmp = positive;
                positive = negative != 0 ? negative+1 : 0;
                negative = tmp+1;
            }
            else{
                positive = 0;
                negative = 0;
            }
        }
        return ans;
    }
};