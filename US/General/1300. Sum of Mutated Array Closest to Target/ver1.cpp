#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int thresholdSum(vector<int>& arr, int value){
        int sum = 0;
        for(int a: arr){
            sum += min(a, value);
        }
        return sum;
    }

    int findBestValue(vector<int>& arr, int target) {
        int low = 0;
        int high = *max_element(arr.begin(), arr.end());
        while(low <= high){
            int mid = (low+high) / 2;
            int sum = thresholdSum(arr, mid);
            if(sum < target){
                low = mid+1;
            }
            else if(sum > target){
                high = mid-1;
            }
            else{
                return mid;
            }
        }
        // low will always be in the right of the decimal result
        if(abs(thresholdSum(arr, low)-target) >= abs(thresholdSum(arr, low-1)-target)){
            return low-1;
        }
        else{
            return low;
        }
    }
};