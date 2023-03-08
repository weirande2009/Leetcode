#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pair<int, int>> nums(n);
        for(int i=0; i<n; i++){
            nums[i] = {nums2[i], nums1[i]};
        }
        // sort by nums2 in a descending order, so in the pq, we can ensure that in the iteration, the nums2[i] is always the smallest one
        sort(nums.begin(), nums.end(), greater<>());
        // maintain a pq that sorted by nums1, we can ensure that the top of pq is the smallest nums1 before
        priority_queue<int, vector<int>, greater<int>> pq;
        long long ans = 0;
        long long sum = 0;  // sum of nums1 in pq
        for(int i=0; i<n; i++){
            pq.push(nums[i].second);
            sum += nums[i].second;
            // if the size is larger than k, pop
            if(pq.size() > k){
                sum -= pq.top();
                pq.pop();
            }
            // here is a case that if we pop the nums[i].second which just push to the pq
            // it seems that we cannot use the corresponding first at this time, but since
            // nums[i].first is in descending order, the first is smaller than before,
            // and the sum*before is already considered and it must be greater than sum*nums[i].first
            // at this situation, so we don't need to change anything.
            if(pq.size() == k)
                ans = max(ans, sum*nums[i].first);
        }
        return ans;
    }
};