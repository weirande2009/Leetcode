#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        vector<unordered_map<int, int>> hashtables(n);  // key is distance, value if length
        hashtables[1][nums[1]-nums[0]] = 2;
        int ans = 2;
        for(int i=2; i<n; i++){
            for(int j=0; j<i; j++){
                if(hashtables[j].find(nums[i]-nums[j]) != hashtables[j].end()){
                    hashtables[i][nums[i]-nums[j]] = max(hashtables[i][nums[i]-nums[j]], hashtables[j][nums[i]-nums[j]]+1);
                }
                else{
                    hashtables[i][nums[i]-nums[j]] = 2;
                }
                ans = max(ans, hashtables[i][nums[i]-nums[j]]);
            }
        }
        return ans;
    }
};