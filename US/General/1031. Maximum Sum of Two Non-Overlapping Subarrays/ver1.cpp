#include <bits/stdc++>
using namespace std;

class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int n = nums.size();
        vector<int> left_first_sum(n);
        vector<int> left_second_sum(n);
        vector<int> right_first_sum(n);
        vector<int> right_second_sum(n);
        int sum = 0;
        // compute left_first_sum
        for(int i=0; i<firstLen; i++){
            sum += nums[i];
        }
        left_first_sum[firstLen-1] = sum;
        for(int i=firstLen; i<n; i++){
            sum += nums[i] - nums[i-firstLen];
            left_first_sum[i] = max(left_first_sum[i-1], sum);
        }
        // compute left_second_sum
        sum = 0;
        for(int i=0; i<secondLen; i++){
            sum += nums[i];
        }
        left_second_sum[secondLen-1] = sum;
        for(int i=secondLen; i<n; i++){
            sum += nums[i] - nums[i-secondLen];
            left_second_sum[i] = max(left_second_sum[i-1], sum);
        }
        // compute right_first_sum
        sum = 0;
        for(int i=n-1; i>=n-firstLen; i--){
            sum += nums[i];
        }
        right_first_sum[n-firstLen] = sum;
        for(int i=n-firstLen-1; i>=0; i--){
            sum += nums[i] - nums[i+firstLen];
            right_first_sum[i] = max(right_first_sum[i+1], sum);
        }
        // compute right_second_sum
        sum = 0;
        for(int i=n-1; i>=n-secondLen; i--){
            sum += nums[i];
        }
        right_second_sum[n-secondLen] = sum;
        for(int i=n-secondLen-1; i>=0; i--){
            sum += nums[i] - nums[i+secondLen];
            right_second_sum[i] = max(right_second_sum[i+1], sum);
        }
        // compute the answer
        int ans = 0;
        // first appear before second
        for(int i=firstLen-1; i<=n-secondLen-1; i++){
            ans = max(ans, left_first_sum[i]+right_second_sum[i+1]);
        }
        // first appear after second
        for(int i=secondLen-1; i<=n-firstLen-1; i++){
            ans = max(ans, left_second_sum[i]+right_first_sum[i+1]);
        }
        return ans;
    }
};