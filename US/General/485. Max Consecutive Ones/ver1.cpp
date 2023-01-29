#include <vector>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int ans = 0;
        for(int num: nums){
            if(num == 0){
                count = 0;
            }
            else{
                count++;
            }
            ans = max(ans, count);
        }
        return ans;
    }
};