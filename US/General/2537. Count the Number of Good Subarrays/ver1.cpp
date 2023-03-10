#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> hashtable;
        long long ans = 0;
        // j is the left side of the sliding window and i i the right side
        // the sliding window maintain that the number of pairs in this sliding window
        // is less than k
        int j=0;
        for(int i=0; i<n; i++){
            // directly decrease on k
            k -= hashtable[nums[i]]++;
            // if k is less than 0, means that the number of pairs in the current 
            // sliding window is greater than k
            while(k <= 0){
                // move the left side and we need to decrease the number of pairs
                // in the sliding window by add to k
                k += --hashtable[nums[j++]];
            }
            // now, we know that, for all l<j, nums[:l+1] is a good array
            ans += j;
        }
        return ans;
    }
};