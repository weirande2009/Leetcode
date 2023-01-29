#include <vector>
#include <numeric>
#include <limits.h>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long dfs_max(vector<int>& weights, vector<vector<long long>>& memo, int i, int k){
        if(weights.size()-i == k){
            return 2*accumulate(weights.begin()+i, weights.end(), 0);
        }
        if(k == 1){
            return weights[i]+weights.back();
        }
        if(memo[i][k] != -1){
            return memo[i][k];
        }
        long long ans = 0;
        for(int j=i; j<weights.size()-k+1; j++){
            ans = max(ans, weights[i]+weights[j]+dfs_max(weights, memo, j+1, k-1));
        }
        memo[i][k] = ans;
        return ans;
    }
    
    long long dfs_min(vector<int>& weights, vector<vector<long long>>& memo, int i, int k){
        if(weights.size()-i == k){
            return 2*accumulate(weights.begin()+i, weights.end(), 0);
        }
        if(k == 1){
            return weights[i]+weights.back();
        }
        if(memo[i][k] != -1){
            return memo[i][k];
        }
        long long ans = INT_MAX;
        for(int j=i; j<weights.size()-k+1; j++){
            ans = min(ans, weights[i]+weights[j]+dfs_min(weights, memo, j+1, k-1));
        }
        memo[i][k] = ans;
        return ans;
    }
    
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        if(k == 1 || n == k){
            return 0;
        }
        vector<int> sum;
        // sum[i] means that we put a bar between i and i+1
        for(int i=0; i<n-1; i++){
            sum.push_back(weights[i]+weights[i+1]);
        }
        // sort the sum, so that we can know the min and max bar
        sort(sum.begin(), sum.end());
        // we first choose the first and last into the result, because they must be chosen and will cost a bar
        long long mn = weights.front()+weights.back();
        long long mx = weights.front()+weights.back();
        // for min, we choose the minimum k-1 bars and for max, we choose the maximum k-1 bars
        for(int i=0; i<k-1; i++){
            mn += sum[i];
            mx += sum[n-i-2];
        }
        return mx - mn;
    }
};