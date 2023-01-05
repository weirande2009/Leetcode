#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int sum = 0;
        int result = 0;
        // (i: j) means the value i's last position is j
        unordered_map<int, int> hashtable;
        int n = nums.size();
        int begin = 0;
        for(int i=0; i<n; i++){
            if(hashtable.find(nums[i]) == hashtable.end()){
                hashtable[nums[i]] = i;
                sum += nums[i];
                result = max(result, sum);
            }
            else{
                // remove until the last position of nums[i]
                for(int j=begin; j<hashtable[nums[i]]; j++){
                    hashtable.erase(nums[j]);
                    sum -= nums[j];
                }
                // set begin as the next to the last nums[i]
                begin = hashtable[nums[i]]+1;
                // reset the position of nums[i]
                hashtable[nums[i]] = i;
            }
        }
        return result;
    }
};