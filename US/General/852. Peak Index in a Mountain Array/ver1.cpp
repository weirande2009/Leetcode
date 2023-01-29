#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int low = 0;
        int high = n-1;
        while(low < high){
            int mid = (low+high) / 2;
            if(mid == 0){
                break;
            }
            if(arr[mid] > arr[mid+1]){
                high = mid-1;
            }
            else if(arr[mid] > arr[mid-1]){
                low = mid+1;
            }
        }
        if(low == 0){
            return max(arr[low], arr[low+1]) == arr[low] ? low : low+1;
        }
        else if(low == n-1){
            return max(arr[low], arr[low-1]) == arr[low] ? low : low-1;
        }
        else{
            return max(arr[low], max(arr[low-1], arr[low+1])) == arr[low] ? low : max(arr[low], max(arr[low-1], arr[low+1])) == arr[low-1] ? low-1 : low+1;
        }
    }
};