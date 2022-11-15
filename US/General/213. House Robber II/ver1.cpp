#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int robbery(vector<int>& nums, int start, int end) {
        int n = nums.size();
        int rob = 0;
        int notrob = 0;
        for(int i=start; i<=end; i++){
            // compute the amount of money of rob and not rob
            int ifrob = nums[i] + notrob;
            int ifnotrob = rob;
            // if rob, for the next house, the amount of rob is "rob"
            rob = max(ifrob, rob);
            // if not rob, for the next house, the amount of not rob is "notrob"
            notrob = max(ifnotrob, notrob);
        }
        return max(rob, notrob);
        
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }
        else if(n == 2){
            return max(nums[0], nums[1]);
        }
        return max(robbery(nums, 0, n-2), robbery(nums, 1, n-1));
    }
};