#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> ans(k);
        vector<pair<int, int>> counts(m);
        for(int i=0; i<m; i++){
            counts[i] = {0, i};
            for(int j=0; j<n; j++){
                if(mat[i][j] == 1){
                    counts[i].first++;
                }
                else{
                    break;
                }
            }
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        for(int i=0; i<m; i++){
            pq.push(counts[i]);
        }
        for(int i=0; i<k; i++){
            ans[i] = pq.top().second;
            pq.pop();
        }
        return ans;
    }
};