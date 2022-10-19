#include <vector>
using namespace std;

// Algorithm: Iterate over the array and use binary search to find target-numbers[i];

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        for(int i=0; i<n; i++){
            int low = i+1;
            int high = n-1;
            while(low < high){
                int mid = (low+high)/2;
                if(numbers[mid] > target-numbers[i]){
                    high = mid-1;
                }
                else if(numbers[mid] < target-numbers[i]){
                    low = mid+1;
                }
                else{
                    return {i+1, mid+1};
                }
            }
            if(numbers[low] == target - numbers[i]){
                return {i+1, low+1};
            }
        }
        return {};
    }
};