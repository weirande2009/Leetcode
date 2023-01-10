#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> hashtable;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(hashtable.find(nums[i]) != hashtable.end()){
                if(abs(hashtable[nums[i]]-i) <= k){
                    return true;
                }
            }
            // update latest index
            hashtable[nums[i]] = i;
        }
        return false;
    }
};
