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
            return p1.second > p2.second;
        });
        int ans = 0;
        for(int i=0; i<worker.size(); i++){
            for(int j=0; j<dif_pro_pair.size(); j++){
                if(dif_pro_pair[j].first <= worker[i]){
                    ans += dif_pro_pair[j].second;
                    break;
                }
            }
        }
        return ans;
    }
};