#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        // means the number of one greater than the number of zero
        int dis = 0;
        // key is the number of ones minus the number of zeros and value is the position
        unordered_map<int, int> hashtable;
        hashtable[0] = -1;
        int ans = 0;
        for(int i=0; i<n; i++){
            if(nums[i] == 0){
                dis--;
            }
            else{
                dis++;
            }
            if(hashtable.find(dis) != hashtable.end()){ // find previous with the same number of distance of the numbers of one and zero
                ans = max(ans, i-hashtable[dis]);
            }
            else{
                hashtable[dis] = i;
            }
        }
        return ans;
    }
};