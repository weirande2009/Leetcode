#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        sort(ages.begin(), ages.end());
        int count = 0;
        int n = ages.size();
        for(int i=0; i<n; i++){
            int lb = ages[i]/2+8;
            int ub = ages[i];
            auto lower_it = lower_bound(ages.begin(), ages.end(), lb);
            auto upper_it = upper_bound(ages.begin(), ages.end(), ub);
            if(upper_it >= lower_it){
                count += upper_it - lower_it;
                if(lower_it <= ages.begin()+i && ages.begin()+i < upper_it){
                    count--;
                }
            }
        }
        return count;
    }
};