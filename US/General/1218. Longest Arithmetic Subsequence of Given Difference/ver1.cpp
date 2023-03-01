#include <bits/stdc++>
using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();
        // key-number, value-{key-dif, value-length}
        unordered_map<int, int> hashtable;
        for(int i=0; i<n; i++){
            if(hashtable.find(arr[i]-difference) != hashtable.end()){
                hashtable[arr[i]] = hashtable[arr[i]-difference]+1;
            }
            hashtable[arr[i]] = max(hashtable[arr[i]], 1);
        }
        int ans = 0;
        for(auto& p: hashtable){
            ans = max(ans, p.second);
        }
        return ans;
    }
};