#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int alice_sum = accumulate(aliceSizes.begin(), aliceSizes.end(), 0);
        int bob_sum = accumulate(bobSizes.begin(), bobSizes.end(), 0);
        int target = (alice_sum + bob_sum) / 2;
        // sa - x + y = sb + x - y -> y = x + (sb-sa) / 2;
        unordered_set<int> hashtable;
        for(int s: aliceSizes){
            hashtable.insert(s + (bob_sum-alice_sum) / 2);
        }
        for(int s: bobSizes){
            if(hashtable.find(s) != hashtable.end()){
                return {s-(bob_sum-alice_sum) / 2, s};
            }
        }
        return {};
    }
};