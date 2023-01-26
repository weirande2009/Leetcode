#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());
        int ans = 0;
        // for each house, use binary search to find the closest heater and compute the distance
        for(int house: houses){
            int low = 0;
            int high = heaters.size()-1;
            while(low < high){
                int mid = (low+high) / 2;
                if(heaters[mid] > house){
                    high = mid-1;
                }
                else if(heaters[mid] < house){
                    low = mid+1;
                }
                else{
                    low = mid;
                    break;
                }
            }
            int mn = INT_MAX;
            if(low > 0){
                mn = min(mn, abs(heaters[low-1]-house));
            }
            if(low < heaters.size()-1){
                mn = min(mn, abs(heaters[low+1]-house));
            }
            mn = min(mn, abs(heaters[low]-house));
            ans = max(ans, mn);
        }
        return ans;
    }
};