#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<int> dp(n, 1);
        int count = 1;
        const int MOD = 1000000007;
        unordered_map<int, int> hashtable;
        for(int i=0; i<n; i++){
            hashtable[arr[i]] = i;
        }
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(arr[i] % arr[j] == 0){
                    int right = arr[i] / arr[j];
                    if(hashtable.find(right) != hashtable.end()){
                        int k = hashtable[right];
                        if(k >= j){
                            long long tmp = ((long long)dp[j]*dp[k]) % MOD;
                            if(j != k){
                                tmp = (tmp*2) % MOD;
                            }
                            dp[i] = (dp[i]+tmp) % MOD;
                        }
                    }
                }
            }
            count = (count+dp[i]) % MOD;
        }
        return count;
    }
};