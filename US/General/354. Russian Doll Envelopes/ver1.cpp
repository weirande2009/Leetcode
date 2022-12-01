#include <vector>
#include <algorithm>
using namespace std;



class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // record[i] means the number of numbers which are less than nums[i]
        vector<int> sub = {nums[0]};
        int m = 1;
        for(int i=1; i<n; i++){
            if(nums[i] > sub[m-1]){
                sub.push_back(nums[i]);
                m++;
            }
            else{
                // find the first in sub that larger than or equal to num[i] and replaced by nums[i]
                // use binary search to find the num, because sub is a increasing array
                int low = 0;
                int high = m-1;
                while(low < high){
                    int mid = (low + high) / 2;
                    if(sub[mid] < nums[i]){
                        low = mid+1;
                    }
                    else if(sub[mid] > nums[i]){
                        high = mid-1;
                    }
                    else{
                        low = mid;
                        break;
                    }
                }
                for(int j=max(low-1, 0); j<=max(low+1, m-1); j++){
                    if(sub[j] >= nums[i]){
                        sub[j] = nums[i];
                        break;
                    }
                }
            }
        }
        return m;
    }
    
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](const vector<int>& v1, const vector<int>& v2){
            // when w1 == w2, sort by h in decreasing order to avoid edge case
            if(v1[0] == v2[0]){
                return v1[1] > v2[1];
            }
            else{
                return v1[0] < v2[0];
            }
        });
        int n = envelopes.size();
        vector<int> envelopes_h;
        // extract dimension h
        for(vector<int>& v: envelopes){
            envelopes_h.push_back(v[1]);
        }
        // now the envelopes have been sorted by w, and when w1 == w2, sorted in decreasing order,
        // so even if w1 == w2, larger h will be in front of smaller h, so w2 cannot envelope w1.
        // Thus, the problem is now a LIS problem (LeetCode 300).
        return lengthOfLIS(envelopes_h);
    }
};