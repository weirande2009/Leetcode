#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> visited(n, false);
        int ans = -1;
        for(int i=0; i<n; i++){
            if(!visited[i]){
                visited[i] = true;
                auto begin_it = nums.begin()+i;
                long long target = (long long)nums[i]*nums[i];
                int count = 1;
                while(1){
                    auto it = lower_bound(begin_it, nums.end(), target);
                    if(it != nums.end() && *it == target){  // if found the target
                        begin_it = it+1;
                        count++;
                        visited[it-nums.begin()] = true;
                        target = (long long)(*it) * (*it);
                    }
                    else{
                        break;
                    }
                }
                if(count > 1)
                    ans = max(ans, count);
            }
        }
        return ans;
    }
};