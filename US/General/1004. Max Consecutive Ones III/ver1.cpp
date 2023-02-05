#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        // record the consecutive zeros and ones, start and end with zero
        vector<int> record;
        int n = nums.size();
        int cur = 0;
        int count = 0;
        for(int i=0; i<n; i++){
            if(nums[i] != cur){
                record.push_back(count);
                cur = nums[i];
                count = 1;
            }
            else{
                count++;
            }
        }
        if(cur == 0){
            record.push_back(count);
        }
        else{
            record.push_back(count);
            record.push_back(0);
        }
        int ans = 0;
        // now we know every consecutive ones' zeros on both side, use sliding window
        for(int i=0; i<record.size(); i++){
            if(i % 2 == 0){  // begin with zero
                for(int j=0; j<record[i]; j++){
                    if(record[i]-j > k || i == record.size()-1){
                        ans = max(ans, k);
                        continue;
                    }
                    int length = record[i] - j + record[i+1];
                    int left = k - record[i] + j;
                    for(int l=i+2; l<record.size() && left>0; l+=2){
                        length += min(left, record[l]); 
                        left -= record[l];
                        if(left >= 0 && l < record.size()-1){
                            length += record[l+1];
                        }
                    }
                    ans = max(ans, length);
                }
            }
            else{
                int length = record[i];
                int left = k;
                for(int l=i+1; l<record.size() && left>0; l+=2){
                    length += min(left, record[l]); 
                    left -= record[l];
                    if(left >= 0 && l < record.size()-1){
                        length += record[l+1];
                    }
                }
                ans = max(ans, length);
            }
        }
        return ans;
    }
};