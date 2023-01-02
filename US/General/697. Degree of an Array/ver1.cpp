#include <vector>
#include <unordered_map>
#include <limits.h>
using namespace std;


class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> counts;
        for(int n: nums){
            counts[n]++;
        }
        int degree = 0;
        for(auto& c: counts){
            degree = max(degree, c.second);
        }
        if(degree == 1){
            return 1;
        }
        unordered_map<int, vector<int>> record;
        for(auto& c: counts){
            if(c.second == degree){
                record[c.first] = {-1, -1};
            }
        }
        
        for(int i=0; i<nums.size(); i++){
            if(record.find(nums[i]) != record.end()){
                if(record[nums[i]][0] == -1){
                    record[nums[i]][0] = i;
                }
                else{
                    record[nums[i]][1] = i;
                }
            }
        }
        int result = INT_MAX;
        for(auto& r: record){
            result = min(result, r.second[1] - r.second[0] + 1);
        }
        return result;
    }
};