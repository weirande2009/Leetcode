#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;


// Algorithm: 2 loops, first sort the array
// In outer loop, trying to find couples for ith number to match the answer.
// In inner loop, use two pointer method. Front one from i+1 and back one from n-1.
// judge result = nums[i]+nums[left]+nums[right]:
// If result == 0: add to results, increase left and decrease right. To avoid duplicate, 
// if the next left is the same as last, left++, same as the right.
// If result < 0, left++
// If result > 0, right--
// This is because this is a sorted array, if result < 0, we need to increase the sum, so we
// can only increase left, same as the right.



class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for(int j=0; j<n-1; j++){
            if(j > 0){
                if(nums[j] == nums[j-1]){
                    continue;
                }
            }
            for(int i=j+1; i<n-1; i++){
                if(i == j){
                    continue;
                }
                if(i > j+1){
                    if(nums[i] == nums[i-1]){
                        continue;
                    }
                }
                int left_p = i+1;
                int right_p = n-1;
                while(left_p < right_p){
                    long long int tmp_sum = nums[j] + nums[i] + nums[left_p] + nums[right_p];
                    if(tmp_sum > INT32_MAX){
                        right_p--;
                        continue;
                    }
                    int sum = nums[j] + nums[i] + nums[left_p] + nums[right_p];
                    if(sum == target){
                        result.emplace_back(vector<int>{nums[j], nums[i], nums[left_p], nums[right_p]});
                        left_p++;
                        right_p--;
                        while(left_p < right_p && nums[left_p] == nums[left_p-1]){
                            left_p++;
                        }
                        while(left_p < right_p && nums[right_p] == nums[right_p+1]){
                            right_p--;
                        } 
                    }
                    else if(sum < target){
                        left_p++;
                    }
                    else{
                        right_p--;
                    }


                }
            } 
        }
        
        return result;
    }
};


int main()
{
    Solution s;
    vector<int> v = {-1,0,1,2,-1,-4};

    s.threeSum(v);

    return 0;

}

