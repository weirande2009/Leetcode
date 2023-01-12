#include <vector>
#include <limits.h>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int target = n / 3;
        vector<int> result;
        int count1 = 0;
        int count2 = 0;
        int candidate1 = INT_MAX;
        int candidate2 = INT_MAX;
        for(int num: nums){
            if(candidate1 == num){
                count1++;
            } else if(candidate2 == num){
                count2++;
            } else if(count1 == 0){
                candidate1 = num;
                count1 = 1;
            } else if(count2 == 0){
                candidate2 = num;
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }
        count1 = 0;
        count2 = 0;
        for(int num: nums){
            if(candidate1 == num){
                count1++;
            }
            else if(candidate2 == num){
                count2++;
            }
        }
        if(count1 > target){
            result.push_back(candidate1);
        }
        if(count2 > target){
            result.push_back(candidate2);
        }
        return result;
    }
};