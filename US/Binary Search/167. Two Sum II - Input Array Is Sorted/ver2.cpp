#include <vector>
using namespace std;

// Algorithm: Use two pointors, low from 0, high from n-1. If sum of them > target, 
// high-- to make the sum smaller. If sum of them < target, low++ to make the sum
// larger.

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int low = 0;
        int high = n-1;
        while(low < high){
            if(numbers[low] + numbers[high] > target){
                high--;
            }
            else if(numbers[low] + numbers[high] < target){
                low++;
            }
            else{
                return {low+1, high+1};
            }
        }
        return {};
    }
};