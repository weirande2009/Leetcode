#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        if(k == 0){
            for(int i=0; i<n; i++){
                if(nums1[i] != nums2[i]){
                    return -1;
                }
            }
            return 0;
        }
        long long gt_count = 0;
        long long lt_count = 0;
        for(int i=0; i<n; i++){
            long long dis = nums1[i]-nums2[i];
            if(abs(dis) % k != 0){
                return -1;
            }
            if(dis >= 0){
                gt_count += dis / k;
            }
            else{
                lt_count += (-dis) / k;
            }
        }
        if(gt_count != lt_count){
            return -1;
        }
        return gt_count;
    }
};