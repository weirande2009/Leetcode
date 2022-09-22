#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_set<int> hash_table;
        for(int i=0; i<nums.size(); i++){
            if(hash_table.find(nums[i]) != hash_table.end()){
                return nums[i];
            }
            hash_table.insert(nums[i]);
        }
        return -1;
    }
}; 