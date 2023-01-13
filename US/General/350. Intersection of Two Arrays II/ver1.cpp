#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> hashtable;
        for(int num: nums1){
            hashtable[num]++;
        }
        vector<int> nums;
        for(int num: nums2){
            if(hashtable[num] > 0){
                nums.push_back(num);
                hashtable[num]--;
            }
        }
        return nums;
    }
};
