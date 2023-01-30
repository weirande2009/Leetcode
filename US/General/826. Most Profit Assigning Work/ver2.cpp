#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>> dif_pro_pair;
        for(int i=0; i<difficulty.size(); i++){
            dif_pro_pair.push_back({difficulty[i], profit[i]});
        }
        // sort by profit
        sort(dif_pro_pair.begin(), dif_pro_pair.end(), [](const pair<int, int>& p1, const pair<int, int>& p2){
            return p1.first < p2.first;
        });
        // sort worker
        sort(worker.begin(), worker.end());
        int best = 0;  // best is the best profit so far
        int ans = 0;
        int i = 0;
        for(int ablility: worker){
            // find the highest profit the worker can do
            while(i < difficulty.size() && dif_pro_pair[i].first <= ablility){
                // record the best so far, because the next worker will have higher or equal ablility
                best = max(best, dif_pro_pair[i++].second);
            }
            ans += best;
        }
        return ans;
    }
};