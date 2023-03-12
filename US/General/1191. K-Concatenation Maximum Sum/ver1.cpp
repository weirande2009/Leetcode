#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        int n = arr.size();
        int sum = accumulate(arr.begin(), arr.end(), 0);
        const int MOD = 1e9+7;
        if(sum > 0){
            int left_max_sum = INT_MIN;
            int left_sum = 0;
            for(int i=0; i<n; i++){
                left_sum += arr[i];
                left_max_sum = max(left_max_sum, left_sum);
            }
            int right_max_sum = INT_MIN;
            int right_sum = 0;
            for(int i=n-1; i>=0; i--){
                right_sum += arr[i];
                right_max_sum = max(right_max_sum, right_sum);
            }

            return ((left_max_sum + right_max_sum) % MOD + ((long long)(sum%MOD) * (k-2)) % MOD) % MOD;
        }
        else{
            int cur_sum = 0;
            int cur_max_sum = INT_MIN;
            for(int i=0; i<n*(k>1 ? 2 : 1); i++){
                cur_sum += arr[i%n];
                if(cur_sum > 0){
                    cur_max_sum = max(cur_max_sum, cur_sum);
                }
                else{
                    cur_sum = 0;
                }
            }
            return max(0, cur_max_sum);
        }
    }
};