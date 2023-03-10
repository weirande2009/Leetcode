#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int element_sum = 0;
        int digit_sum = 0;
        for(int num: nums){
            element_sum += num;
            string s = to_string(num);
            for(char c: s){
                digit_sum += c - '0';
            }
        }
        return abs(element_sum-digit_sum);
    }
};