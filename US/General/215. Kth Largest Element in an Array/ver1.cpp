#include <vector>
using namespace std;

class Solution {
public:
    void swap(int& i, int& j){
        int tmp = i;
        i = j;
        j = tmp;
    }
    
    int search(vector<int>& nums, int begin, int end){
        int pivot = begin;
        int i = begin+1;
        int j = end;
        while(i <= j){
            if(nums[pivot] < nums[i]){
                swap(nums[i], nums[j]);
                j--;
            }
            else{
                i++;
            }
        }
        swap(nums[pivot], nums[j]);
        return j;
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        while(1){
            int s = search(nums, low, high);
            if(s < n-k){
                low = s+1;
            }
            else if(s > n-k){
                high = s-1;
            }
            else{
                return nums[s];
            }
        }
        return 0;
    }
};