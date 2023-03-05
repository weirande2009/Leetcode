#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // add the factors of n to the map
    void computeFactor(unordered_map<int, int>& factors, int n){
        int num = n;
        for(int j=2; j*j<=n && num != 1; j++){
            while(num % j == 0){
                factors[j]++;
                num /= j;
            }
        }
        if(num >= 2){
            factors[num]++;
        }
    }
    
    int findValidSplit(vector<int>& nums) {
        // key-factor, value-the number of key as a factor in the array
        unordered_map<int, int> factors;
        int n = nums.size();
        for(int i=0; i<n; i++){
            computeFactor(factors, nums[i]);
        }
        // record the current array factor
        unordered_map<int, int> cur_factors;
        for(int i=0; i<n-1; i++){
            // add the current number to map
            computeFactor(cur_factors, nums[i]);
            // compare the two maps, if there is factor in total map whose number is greater than current map, means that this factor
            // exists in the latter array
            bool coprime = true;
            for(auto& p: cur_factors){
                if(p.second < factors[p.first]){
                    coprime = false;
                    break;
                }
            }
            if(coprime){
                return i;
            }
        }
        return -1;
    }
};