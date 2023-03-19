#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int n = nums.size();
        unordered_map<int, int> hashtable;
        for(int i=0; i<n; i++){
            nums[i] = (nums[i] % value + value) % value;
            hashtable[nums[i]]++;
        }
        int ans = 0;
        int num = 0;
        bool first = true;
        while(1){
            if(hashtable[num] == 0){
                return ans;
            }
            hashtable[num]--;
            ans++;
            num = (num+1)%value;
        }
        return ans;
    }
};