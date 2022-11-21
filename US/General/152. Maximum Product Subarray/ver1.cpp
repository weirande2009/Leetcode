#include <vector>
using namespace std;



class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if(n == 0){
            return 0;
        }
        int mx = nums[0];
        int mn = nums[0];
        int product = mx;
        for(int i=1; i<n; i++){
            // keep track of the max number
            int tmp_mx = max(nums[i], max(mx*nums[i], mn*nums[i]));
            // keep track of the min number, because min number may be saved by a negative number
            mn = min(nums[i], min(mx*nums[i], mn*nums[i]));
            mx = tmp_mx;
            product = max(product, mx);
        }
        return product;
    }
};