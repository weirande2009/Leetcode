#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    void flip(vector<int>& arr, int k){
        int left = 0;
        int right = k-1;
        while(left < right){
            int tmp = arr[left];
            arr[left] = arr[right];
            arr[right] = tmp;
            left++;
            right--;
        }
    }

    vector<int> pancakeSort(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans;
        int max_target = n-1;
        while(max_target > 0){
            int mx_pos = 0;
            for(int i=1; i<=max_target; i++){
                if(arr[i] > arr[mx_pos]){
                    mx_pos = i;
                }
            }
            if(mx_pos != max_target){
                // with two flip, we can flip the max number so far to the target position
                ans.push_back(mx_pos+1);
                flip(arr, mx_pos+1);
                ans.push_back(max_target+1);
                flip(arr, max_target+1);
            }
            max_target--;
        }
        return ans;
    }
};