#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash_table;
        for(int i=0; i<nums.size(); i++){
            auto it = hash_table.find(target - nums[i]);
            if(it != hash_table.end()){
                return {i, it->second};
            }
            hash_table[nums[i]] = i;
        }
        return {};
    }
};




