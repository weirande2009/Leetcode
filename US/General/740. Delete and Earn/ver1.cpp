#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        // this is like the rob probrem, we cannot rob the adjacent houses, here we cannot 
        // take the adjacent numbers
        map<int, int> hashtable;
        for(int num: nums){
            hashtable[num]++;
        }
        int take = 0;
        int notake = 0;
        int last = -1;
        for(auto& p: hashtable){
            int last_take = take;
            if(p.first == last - 1 || p.first == last + 1){
                take = max(take, notake + p.first*p.second);
                notake = last_take;
            }
            else{
                take = max(notake, take) + p.first*p.second;
                notake = max(notake, last_take);
            }
            last = p.first;
        }
        return max(take, notake);
    }
};