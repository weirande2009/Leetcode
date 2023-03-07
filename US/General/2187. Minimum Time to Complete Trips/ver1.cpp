#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool completed(vector<int>& time, int totalTrips, long long t){
        for(int i=0; i<time.size(); i++){
            totalTrips -= t / time[i];
            if(totalTrips <= 0){
                return true;
            }
        }
        return false;
    }

    long long minimumTime(vector<int>& time, int totalTrips) {
        int n = time.size();
        int ans = 0;
        long long low = 1;
        long long high = (long long)(*min_element(time.begin(), time.end())) * totalTrips;
        while(low <= high){
            long long mid = (high + low) / 2;
            if(completed(time, totalTrips, mid)){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
};