#include <vector>
#include <unordered_set>
using namespace std;


class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_set<int> hashtable;
        int n = nums.size();
        for(int i=0; i<n; i++){
            hashtable.insert(i+1);
        }
        for(int i: nums){
            hashtable.erase(i);
        }
        vector<int> result;
        for(int i: hashtable){
            result.push_back(i);
        }
        return result;
    }
};