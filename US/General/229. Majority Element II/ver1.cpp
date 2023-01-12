#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int target = n / 3;
        vector<int> result;
        unordered_map<int, int> hashtable;
        for(int num: nums){
            hashtable[num]++;
        }
        for(auto& p: hashtable){
            if(p.second > target){
                result.push_back(p.first);
            }
        }
        return result;
    }
};
