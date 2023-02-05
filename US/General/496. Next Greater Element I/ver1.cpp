#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> hashtable;
        for(int i=0; i<nums2.size(); i++){
            hashtable[nums2[i]] = i;
        }
        int n = nums1.size();
        vector<int> ans(n, -1);
        for(int i=0; i< nums1.size(); i++){
            for(int j=hashtable[nums1[i]]; j<nums2.size(); j++){
                if(nums2[j] > nums1[i]){
                    ans[i] = nums2[j];
                    break;
                }
            }
        }
        return ans;
    }
};