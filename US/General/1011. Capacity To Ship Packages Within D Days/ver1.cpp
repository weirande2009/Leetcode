#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canShip(vector<int>& weights, int weight, int days){
        int i = 0;
        while(days > 0){
            int w = weight;
            while(1){
                if(i < weights.size() && w - weights[i] >= 0){
                    w -= weights[i++];
                }
                else{
                    break;
                }
            }
            if(i == weights.size()){
                return true;
            }
            days--;
        }
        return false;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        while(low <= high){
            int mid = (low + high) / 2;
            if(canShip(weights, mid, days)){
                high = mid-1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};