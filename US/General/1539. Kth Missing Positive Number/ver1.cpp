#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        if(arr[0] > k){
            return k;
        }
        int n = arr.size();
        auto begin_it = arr.begin();
        int cur = arr[0];
        k -= arr[0]-1;
        while(1){
            auto it = upper_bound(begin_it, arr.end(), cur+k);
            // compute how many numbers are in the array
            int in_array_count = it-begin_it;
            if(it == arr.end()){
                return arr.back() + k - ((arr.back()-(*begin_it)+1)-in_array_count);
            }
            int total_number = (*it) - (*begin_it);
            if(k > total_number - in_array_count){
                k -= total_number - in_array_count;
                begin_it = it;
                cur = *it;
            }
            else{
                --it;
                int last_total_number = (*it) - (*begin_it);
                int last_in_array_count = it-begin_it;
                k -= last_total_number - last_in_array_count;
                return (*it) + k;
            }
        }
        return 0;
    }
};