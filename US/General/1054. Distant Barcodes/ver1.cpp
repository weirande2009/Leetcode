#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        int n = barcodes.size();
        vector<int> ans(n);
        unordered_map<int, int> hashtable;
        priority_queue<pair<int, int>, vector<pair<int, int>>> pq;
        for(int barcode: barcodes){
            hashtable[barcode]++;
        }
        for(pair<int, int> p: hashtable){
            pq.push({p.second, p.first});
        }
        int i=0;
        while(!pq.empty()){
            pair<int, int> first = pq.top();
            pq.pop();
            if(pq.empty()){
                ans[i++] = first.second;
                break;
            }
            pair<int, int> second = pq.top();
            pq.pop();
            ans[i++] = first.second;
            first.first--;
            ans[i++] = second.second;
            second.first--;
            if(first.first > 0){
                pq.push(first);
            }
            if(second.first > 0){
                pq.push(second);
            }
        }
        return ans;
    }
};