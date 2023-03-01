#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void merge(vector<int> &nums, int low, int mid, int high){
        if(low >= high){
            return;
        }
        int l = low;  // beginning of the first array
        int r = mid+1;  // beginning of the second array
        int n = high - low + 1;
        int i = 0;  // the index in the new array
        vector<int> sorted_arr(n);
        while(l <= mid && r <= high){
            sorted_arr[i++] = nums[l] < nums[r] ? nums[l++] : nums[r++];
        }
        // iterate over the left
        while(l <= mid){
            sorted_arr[i++] = nums[l++];
        }
        while(r <= high){
            sorted_arr[i++] = nums[r++];
        }
        // copy to nums
        for(int j=0; j<n; j++){
            nums[low+j] = sorted_arr[j];
        }
    }

    void mergeSort(vector<int>& nums, int begin, int end){
        if(begin >= end){
            return;
        }
        int mid = (begin + end) / 2;
        mergeSort(nums, begin, mid);
        mergeSort(nums, mid+1, end);
        merge(nums, begin, mid, end);
    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);
        return nums;
    }
};