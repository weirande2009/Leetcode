#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }
        else if(n == 2){
            return max(nums[0], nums[1]);
        }
        int rob = 0;
        int notrob = 0;
        for(int i=0; i<n; i++){
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
};