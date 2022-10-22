#include <vector>
using namespace std;

// Algorithm: First, set nums[i] <= 0 as n+1. Then, set a pointor right to record the current
// useful region. Then, iterate over the nums. Put useless number to right and right--. Useless
// numbers include: number >= n, number > right(will not be the missing number), duplicate number.

class Solution {
public:
    void swap(int& a, int& b){
        int tmp = a;
        a = b;
        b = tmp;
    }
    
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i] <= 0){
                nums[i] = n+1;
            }
        }
        int right = n-1;
        int i = 0;
        while(i < n && i <= right){
            if(nums[i] > right){
                swap(nums[i], nums[right--]);
            }
            else{
                if(nums[i] == i+1){
                    i++;
                }
                else{
                    if(nums[i] == nums[nums[i]-1]){
                        swap(nums[i], nums[right--]);
                    }
                    else{
                        swap(nums[i], nums[nums[i]-1]);
                    }
                }
            }
        }
        for(int i=0; i<n; i++){
            if(nums[i] != i+1){
                return i+1;
            }
        }
        return n+1;
    }
};