#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();
        // find the bit length of the max number
        int L = 0;
        for(int num: nums){
            int l = 0;
            while(num > 0){
                l++;
                num /= 2;
            }
            L = max(L, l);
        }
        unordered_set<int> hashtable;
        int max_xor = 0;
        int cur_xor;
        for(int i=L-1; i>=0; i--){
            max_xor <<= 1;
            // check the next bit
            cur_xor = max_xor | 1;
            hashtable.clear();
            // iterate over the nums to push the first i bits to the hashtable
            for(int num: nums){
                hashtable.insert(num >> i);
            }
            // search in the hashtable to find whether there is a pair of the first i bits whose xor are equal to the cur_xor
            for(int num: hashtable){
                if(hashtable.find(cur_xor ^ num) != hashtable.end()){
                    max_xor = cur_xor;
                    break;  // one is enough
                }
            }
        }
        return max_xor;
    }
};