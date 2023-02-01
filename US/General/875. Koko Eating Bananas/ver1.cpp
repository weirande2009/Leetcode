#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool ok(vector<int>& piles, int h, int k){
        for(int p: piles){
            h -= ceil((double)p / k);
        }
        return h >= 0;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        while(low <= high){
            int mid = (low+high) / 2;
            if(ok(piles, h, mid)){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};