#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int nums1_length = nums1.size();
        int nums2_length = nums2.size();
        if(nums1_length == 0){
            if(nums2_length % 2){
                return nums2[nums2_length/2];
            }
            else{
                return (nums2[nums2_length/2] + nums2[nums2_length/2-1]) / 2.0;
            }
        }
        else if(nums2_length == 0){
            if(nums1_length % 2){
                return nums1[nums1_length/2];
            }
            else{
                return (nums1[nums1_length/2] + nums1[nums1_length/2-1]) / 2.0;
            }
        }
        int total_length = nums1_length + nums2_length;
        if(nums1_length == 1){
            nums2.push_back(nums1[0]);
            sort(nums2.begin(), nums2.end());
            if(total_length % 2){
                return nums2[total_length/2];
            }
            else{
                return (nums2[total_length/2] + nums2[total_length/2-1]) / 2.0;
            }
        }
        else if(nums2_length == 1){
            nums1.push_back(nums2[0]);
            sort(nums1.begin(), nums1.end());
            if(total_length % 2){
                return nums1[total_length/2];
            }
            else{
                return (nums1[total_length/2] + nums1[total_length/2-1]) / 2.0;
            }
        }
        int nums1_begin = 0;
        int nums1_end = nums1_length - 1;
        int nums2_begin = 0;
        int nums2_end = nums2_length - 1;
        int last_nums1_begin = nums1_begin;
        int last_nums1_end = nums1_end;
        int last_nums2_begin = nums2_begin;
        int last_nums2_end = nums2_end;
        while(1){
            int num1_sum_index = nums1_begin + nums1_end;
            int num2_sum_index = nums2_begin + nums2_end;
            int num1_mid = num1_sum_index / 2;
            int num2_mid = num2_sum_index / 2;
            double num1_median;
            if(num1_sum_index % 2){
                num1_median = (nums1[num1_mid] + nums1[num1_mid+1]) / 2.0;
            }
            else{
                num1_median = nums1[num1_mid];
            }
            int num2_median;
            if(num2_sum_index % 2){
                num2_median = (nums2[num2_mid] + nums2[num2_mid+1]) / 2.0;
            }
            else{
                num2_median = nums2[num2_mid];
            }
            if(num1_median > num2_median){
                if(num1_sum_index % 2){
                    nums1_end = num1_mid+1;
                }
                else{
                    nums1_end = num1_mid;
                }
                nums2_begin = num2_mid;
            }
            else if(num1_median < num2_median){
                if(num2_sum_index % 2){
                    nums2_end = num2_mid+1;
                }
                else{
                    nums2_end = num2_mid;
                }
                nums1_begin = num1_mid;
            }
            else{
                nums1.push_back(nums2[0]);
                sort(nums1.begin(), nums1.end());
                if(total_length % 2){
                    return nums1[total_length/2];
                }
                else{
                    return (nums1[total_length/2] + nums1[total_length/2-1]) / 2.0;
                }
            }
            if(last_nums1_begin == nums1_begin && last_nums1_end == nums1_end && last_nums2_begin == nums2_begin && last_nums2_end == nums2_end){
                int less_num = nums1_begin + nums2_begin;
                int larger_num = nums1_length - nums1_end - 1 + nums2_length - nums2_end - 1;
                vector<int> left_nums = {nums1[nums1_begin], nums1[nums1_end], nums2[nums2_begin], nums2[nums2_end]};
                sort(left_nums.begin(), left_nums.end());
                if(total_length % 2){
                    if(larger_num > less_num){
                        return left_nums[(larger_num-less_num)/2+2];
                    }
                    else{
                        return left_nums[(larger_num-less_num)/2+1];
                    }
                }
                else{
                    return (left_nums[(larger_num-less_num)/2+1] + left_nums[(larger_num-less_num)/2+2]) / 2.0;
                }
            }
            last_nums1_begin = nums1_begin;
            last_nums1_end = nums1_end;
            last_nums2_begin = nums2_begin;
            last_nums2_end = nums2_end;
        }
        return 0;
    }
};

int main(){
    Solution s;
    vector<int> nums1 = {1};
    vector<int> nums2 = {2, 3, 4};
    double mid = s.findMedianSortedArrays(nums1, nums2);
    cout << mid << endl;
    return 0;
}




