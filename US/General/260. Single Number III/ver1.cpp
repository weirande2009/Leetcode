#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int, int> hashtable;
        for(int n: nums){
            hashtable[n]++;
        }
        vector<int> result;
        for(auto& p: hashtable){
            if(p.second == 1){
                result.push_back(p.first);
            }
        }
        return result;
    }
};