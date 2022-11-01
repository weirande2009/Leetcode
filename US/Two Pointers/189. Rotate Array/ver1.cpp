#include <vector>
using namespace std;


class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;
        vector<int> result(nums.begin()+n-k, nums.end());
        for(int i=n-k-1; i>=0; i--){
            nums[(i+k)%n] = nums[i];
        }
        for(int i=0; i<k; i++){
            nums[i] = result[i];
        }
        return;
    }
};