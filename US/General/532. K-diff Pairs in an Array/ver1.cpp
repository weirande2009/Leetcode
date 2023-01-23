#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int count = 0;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if(nums.size() == 2){
            if(nums[1] - nums[0] == k){
                return 1;
            }
            else{
                return 0;
            }
        }
        if(k == 0){
            unordered_map<int, int> hashtable;
            for(int num: nums){
                hashtable[num]++;
            }
            for(auto& p: hashtable){
                if(p.second > 1){
                    count++;
                }
            }
            return count;
        }
        for(int i=0; i<n; i++){
            if(i != n-1 && nums[i] == nums[i+1]){
                continue;
            }
            int low = i+1;
            int high = n-1;
            int target = nums[i]+k;
            while(low < high){
                int mid = (low+high) / 2;
                if(nums[mid] > target){
                    high = mid-1;
                }
                else if(nums[mid] < target){
                    low = mid+1;
                }
                else{
                    low = mid;
                    break;
                }
            }
            if(nums[low] == target){
                count++;
            }
        }
        return count;
    }
};