#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        unordered_set<int> hashtable;
        priority_queue<int> pq;
        int n = nums.size();
        int low = INT_MAX;
        // push all possible odd number
        for(int num: nums){
            if(num%2 == 1){
                num *= 2;
            }
            pq.push(num);
            low = min(low, num);
        }
        int ans = pq.top()-low;
        while(!pq.empty()){
            int num = pq.top();
            pq.pop();
            if(num % 2 == 0){
                low = min(low, num/2);
                pq.push(num/2);
                ans = min(ans, pq.top()-low);
            }
            else{
                break;
            }
        }
        return ans;
    }
};