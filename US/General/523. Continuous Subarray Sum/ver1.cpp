#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(nums.size() < 2){
            return false;
        }
        // key is the modulo value of the cumsum before the index of the value, and value of the leftmost index
        unordered_map<int, int> hashtable;
        int n = nums.size();
        hashtable[0] = 0;
        int sum = 0;
        for(int i=0; i<n; i++){
            // compute the cumsum
            sum += nums[i];
            // check we can find another subarray with the same modulo
            if(hashtable.find(sum%k) != hashtable.end()){
                if(hashtable[sum%k] < i){ // if the index is left, which means the length is at least two
                    return true;
                }
            }
            else{
                hashtable[sum%k] = i + 1;
            }
        }
        return false;
    }
};