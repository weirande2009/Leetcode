#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // for each element, [0] is the position, [1] is the speed and [2] is the time it takes to this position
        stack<vector<double>> s;
        vector<pair<int, int>> cars;
        int n = position.size();
        for(int i=0; i<n; i++){
            cars.push_back({position[i], speed[i]});
        }
        sort(cars.begin(), cars.end());
        s.push({(double)cars[n-1].first, (double)cars[n-1].second, 0});
        for(int i=n-2; i>=0; i--){
            if(cars[i].second <= s.top()[1]){
                s.push({(double)cars[i].first, (double)cars[i].second, 0});
            }
            else{
                // compute the meeting position
                double prev_t = s.top()[2];
                double a1 = cars[i].first + prev_t*cars[i].second;
                double b1 = cars[i].second;
                double a2 = s.top()[0];
                double b2 = s.top()[1];
                if(a1 - a2 >= 10e-6){  // already reach a2
                    continue;
                }
                double t = (a2-a1) / (b1-b2);
                double p = a1 + b1*t;
                if(p-target > 10e-6){  // beyond the target
                    // add the current car to the stack
                    s.push({(double)cars[i].first, (double)cars[i].second, 0});
                }
                else{
                    s.pop();
                    s.push({p, b2, t+prev_t});
                }
            }
        }
        return s.size();
    }
};