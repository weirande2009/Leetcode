#include <vector>
#include <unordered_set>
using namespace std;

// Algorithm: O(n), First, insert all nums into an unordered set. Then, for each num in nums,
// try to find whether there is nums[i]+1, if not, find in set from j=nums[i]-1 to unlimited small.
// when j is not in set, record max length, break. Then start the next num in nums.


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> hashtable;
        for(int i=0; i<n; i++){
            hashtable.insert(nums[i]);
        }
        int max_length = 0;
        for(int i=0; i<n; i++){
            auto f = hashtable.find(nums[i]+1);
            if(f == hashtable.end()){
                for(int j=nums[i]-1; ; j--){
                    auto tmp = hashtable.find(j);
                    if(tmp == hashtable.end()){
                        if(nums[i]-j > max_length){
                            max_length = nums[i]-j;
                        }
                        break;
                    }
                }
            }
        }
        return max_length;
    }
};

int main(){
    vector<int> nums = {100,4,200,1,3,2};
    Solution s;
    s.longestConsecutive(nums);


}