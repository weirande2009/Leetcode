#include <iostream>
#include <vector>
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
        int nums1_begin = 0;
        int nums1_end = nums1_length - 1;
        int nums2_begin = 0;
        int nums2_end = nums2_length - 1;
        int last_nums1_begin = nums1_begin;
        int last_nums1_end = nums1_end;
        int last_nums2_begin = nums2_begin;
        int last_nums2_end = nums2_end;
        while(1){
            int num1_mid = (nums1_begin + nums1_end) / 2;
            int num2_mid = (nums2_begin + nums2_end) / 2;
            if(nums1[num1_mid] > nums2[num2_mid]){
                nums1_end = num1_mid;
                nums2_begin = num2_mid;
            }
            else{
                nums1_begin = num1_mid;
                nums2_end = num2_mid;
            }
            if(last_nums1_begin == nums1_begin && last_nums1_end == nums1_end && last_nums2_begin == nums2_begin && last_nums2_end == nums2_end){
                int less_num = nums1_begin + nums2_begin;
                int larger_num = nums1_length - nums1_end - 1 + nums2_length - nums2_end - 1;
                int left_num = total_length - larger_num - less_num;
                if(total_length % 2){
                    if(left_num == 2){
                        if(larger_num > less_num){
                            return nums1[nums1_begin] > nums2[nums2_begin] ? nums1[nums1_begin] : nums2[nums2_begin];
                        }
                        else{
                            return nums1[nums1_begin] > nums2[nums2_begin] ? nums2[nums2_begin] : nums1[nums1_begin];
                        }
                    }
                    else if(left_num == 3){
                        // middle one
                        if(nums1_begin == nums1_end){
                            if(nums1[nums1_begin] > nums2[nums2_end]){
                                return nums2[nums2_end];
                            }
                            else if(nums1[nums1_begin] < nums2[nums2_begin]){
                                return nums2[nums2_begin];
                            }
                            else{
                                return nums1[nums1_begin];
                            }
                        }
                        else{
                            if(nums2[nums2_begin] > nums1[nums1_end]){
                                return nums1[nums1_end];
                            }
                            else if(nums2[nums2_begin] < nums1[nums1_begin]){
                                return nums1[nums1_begin];
                            }
                            else{
                                return nums2[nums2_begin];
                            }
                        }
                    }
                    else if(left_num == 4){
                        if(nums1[nums1_begin] < nums2[nums2_begin] && nums1[nums1_end] > nums2[nums2_end]){
                            if(larger_num > less_num){
                                return nums2[nums2_end];
                            }
                            else{
                                return nums2[nums2_begin];
                            }
                        }
                        else{
                            if(larger_num > less_num){
                                return nums1[nums1_end];
                            }
                            else{
                                return nums1[nums1_begin];
                            }
                        }
                    }
                }
                else{
                    if(left_num == 2){
                        return (nums1[nums1_begin] + nums2[nums2_begin]) / 2.0;
                    }
                    else if(left_num == 3){
                        // middle one
                        if(nums1_begin == nums1_end){
                            if(larger_num > less_num){
                                if(nums1[nums1_begin] < nums2[nums2_begin]){
                                    return (nums2[nums2_begin] + nums2[nums2_end]) / 2.0;
                                }
                                else{
                                    return (nums1[nums1_begin] + nums2[nums2_end]) / 2.0;
                                }
                            }
                            else{
                                if(nums1[nums1_begin] > nums2[nums2_end]){
                                    return (nums2[nums2_begin] + nums2[nums2_end]) / 2.0;
                                }
                                else{
                                    return (nums2[nums2_begin] + nums1[nums1_begin]) / 2.0;
                                }
                            }
                        }
                        else{
                            if(larger_num > less_num){
                                if(nums2[nums2_begin] < nums1[nums1_begin]){
                                    return (nums1[nums1_begin] + nums1[nums1_end]) / 2.0;
                                }
                                else{
                                    return (nums2[nums2_begin] + nums1[nums1_end]) / 2.0;
                                }
                            }
                            else{
                                if(nums2[nums2_begin] > nums1[nums1_end]){
                                    return (nums1[nums1_begin] + nums1[nums1_end]) / 2.0;
                                }
                                else{
                                    return (nums1[nums1_begin] + nums2[nums2_begin]) / 2.0;
                                }
                            }
                        }
                    }
                    else if(left_num == 4){
                        if(nums1[nums1_begin] < nums2[nums2_begin] && nums1[nums1_end] > nums2[nums2_end]){
                            return (nums2[nums2_begin] + nums2[nums2_end]) / 2.0;
                        }
                        else{
                            return (nums1[nums1_begin] + nums1[nums1_end]) / 2.0;
                        }
                    }
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
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {-1, 3};
    double mid = s.findMedianSortedArrays(nums1, nums2);
    cout << mid << endl;
    return 0;
}




