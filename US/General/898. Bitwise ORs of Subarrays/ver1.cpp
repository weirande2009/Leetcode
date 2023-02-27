#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        int n = arr.size();
        vector<unordered_set<int>> hashtables(n);
        hashtables[0] = {arr[0]};
        for(int i=1; i<n; i++){
            for(int o: hashtables[i-1]){
                hashtables[i].insert(o | arr[i]);
            }
            hashtables[i].insert(arr[i]);
        }
        unordered_set<int> hashtable;
        for(int i=0; i<n; i++){
            for(int o: hashtables[i]){
                hashtable.insert(o);
            }
        }
        return hashtable.size();
    }
};