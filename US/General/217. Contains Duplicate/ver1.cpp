#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> hashtable;
        for(int num: nums){
            if(hashtable.find(num) == hashtable.end()){
                hashtable.insert(num);
            }
            else{
                return true;
            }
        }
        return false;
    }
};