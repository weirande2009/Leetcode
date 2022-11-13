#include <vector>
#include <unordered_map>
using namespace std;


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> count;
        for(int i: nums){
            count[i]++;
        }
        for(const auto& a: count){
            if(a.second == 1){
                return a.first;
            }
        }
        return 0;
    }
};