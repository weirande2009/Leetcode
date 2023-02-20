#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int i=0;
        int j=0;
        vector<vector<int>> ans;
        while(i < n1 && j < n2){
            if(nums1[i][0] == nums2[j][0]){
                ans.push_back({nums1[i][0], nums1[i][1]+nums2[j][1]});
                i++;
                j++;
            }
            else if(nums1[i][0] < nums2[j][0]){
                ans.push_back(nums1[i]);
                i++;
            }
            else {
                ans.push_back(nums2[j]);
                j++;
            }
        }
        if(i < n1){
            ans.insert(ans.end(), nums1.begin()+i, nums1.end());
        }
        if(j < n2){
            ans.insert(ans.end(), nums2.begin()+j, nums2.end());
        }
        return ans;
    }
};