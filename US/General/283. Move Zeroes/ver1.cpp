#include <vector>
using namespace std;

class Solution {
public:
    void swap(int& i, int& j){
        int tmp = i;
        i = j;
        j = tmp;
        
    }
    
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int right = n-1;
        for(int i=n-1; i>=0; i--){
            if(nums[i] == 0){
                for(int j=i; j<right; j++){
                    swap(nums[j], nums[j+1]);
                }
                right--;
            }
        }
    }
};