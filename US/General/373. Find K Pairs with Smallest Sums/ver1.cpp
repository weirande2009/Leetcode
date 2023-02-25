#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        // the vector is length of 3, {nums1[i], nums2[j], j}
        auto comparator = [](const vector<int>& v1, const vector<int>& v2){
            return v1[0]+v1[1] > v2[0]+v2[1];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(comparator)> pq(comparator);
        // first push all nums1 with nums2[0]
        for(int i=0; i<nums1.size(); i++){
            pq.push({nums1[i], nums2[0], 0});
        }
        vector<vector<int>> ans;
        while(k > 0 && !pq.empty()){
            auto& v = pq.top();
            ans.push_back({v[0], v[1]});
            if(v[2]+1 != nums2.size()){  // if there is no more pairs
                pq.push({v[0], nums2[v[2]+1], v[2]+1});
            }
            pq.pop();
            k--;
        }
        return ans;
    }
};
