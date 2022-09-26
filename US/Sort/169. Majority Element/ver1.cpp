#include <vector>
#include <unordered_map>
using namespace std;

// Algorithm: O(n). Use hashtable to record the number of each value.

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> hashtable;
        int max_num = 0;
        int max_int = 0;
        for(int i=0; i<n; i++){
            auto f = hashtable.find(nums[i]);
            if(f == hashtable.end()){
                hashtable[nums[i]] = 1;
            }
            else{
                hashtable[nums[i]]++;
            }
            if(hashtable[nums[i]] > max_num){
                max_num = hashtable[nums[i]];
                max_int = nums[i];
            }
            
        }
        return max_int;
    }
};