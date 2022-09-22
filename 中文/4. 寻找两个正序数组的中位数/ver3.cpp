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
        int k = (nums1_length + nums2_length) / 2;
        if((nums1_length + nums2_length) % 2){
            k++;
        }
        int init_k = k;
        int nums1_begin = 0;
        int nums2_begin = 0;
        int nums1_index;
        int nums2_index;
        while(1){
            if(k == 1){  // 若k=1，则返回
                int min_num = nums1[nums1_begin] > nums2[nums2_begin] ? nums2[nums2_begin] : nums1[nums1_begin];
                if((nums1_length + nums2_length) % 2){
                    return min_num;
                }
                else{
                    if(nums1[nums1_begin] < nums2[nums2_begin]){
                        if(nums1_begin == nums1_length - 1){  // 数组1只有一个数
                            return (nums1[nums1_begin] + nums2[nums2_begin]) / 2.0;
                        }
                        else{
                            int second = nums1[nums1_begin+1] > nums2[nums2_begin] ? nums2[nums2_begin] : nums1[nums1_begin+1];
                            return (min_num + second) / 2.0;
                        }
                    }
                    else{
                        if(nums2_begin == nums2_length - 1){  // 数组2只有一个数
                            return (nums1[nums1_begin] + nums2[nums2_begin]) / 2.0;
                        }
                        else{
                            int second = nums2[nums2_begin+1] > nums1[nums1_begin] ? nums1[nums1_begin] : nums2[nums2_begin+1];
                            return (min_num + second) / 2.0;
                        }
                    }
                }
            }
            nums1_index = k/2-1+nums1_begin;
            if(nums1_index >= nums1_length){  // 越界，直接取最后一个
                nums1_index = nums1_length - 1;
            }
            nums2_index = k/2-1+nums2_begin;
            if(nums2_index >= nums2_length){  // 越界，直接取最后一个
                nums2_index = nums2_length - 1;
            }
            if(nums1[nums1_index] > nums2[nums2_index]){
                nums2_begin = nums2_index + 1;
            }
            else{
                nums1_begin = nums1_index + 1;
            }
            
            k = init_k - nums2_begin - nums1_begin;
            if(nums1_begin == nums1_length){  // 若数组1为空，则直接返回另一个数组的第k个元素
                if((nums1_length + nums2_length) % 2){
                    return nums2[k+nums2_begin-1];
                }
                else{
                    return (nums2[k+nums2_begin-1]+nums2[k+nums2_begin]) / 2.0;
                }
            }
            if(nums2_begin == nums2_length){  // 若数组2为空，则直接返回另一个数组的第k个元素
                if((nums1_length + nums2_length) % 2){
                    return nums1[k+nums1_begin-1];
                }
                else{
                    return (nums1[k+nums1_begin-1]+nums1[k+nums1_begin]) / 2.0;
                }
            }

        }
    }
};

int main(){
    Solution s;
    vector<int> nums1 = {2, 3};
    vector<int> nums2 = {1};
    double mid = s.findMedianSortedArrays(nums1, nums2);
    cout << mid << endl;
    return 0;
}




