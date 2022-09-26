#include <string>
#include <vector>
using namespace std;

// Algorithm: Define a judge algorithm for each number. Convert all the numbers to string
// For two number, from the first single number to the last, if a[i] > b[i], then a > b, 
// if a[i] < b[i], then a < b. If a[i] == b[i], if none come to end, i++. if a comes to end, 
// we need to judge a.substr(i+1) with b. The same if b comes to end.

class Solution {
public:
    
    bool larger(string a, string b){
        int l_a = a.length();
        int l_b = b.length();
        int i=0;
        while(1){
            if(a[i] > b[i]){
                return true;
            }
            else if(a[i] < b[i]){
                return false;
            }
            else{
                if(i+1 == l_a && i+1 == l_b){
                    return true;
                }
                else if(i+1 == l_a){
                    return larger(a, b.substr(i+1));
                }
                else if(i+1 == l_b){
                    return larger(a.substr(i+1), b);
                }
                else{
                    i++;
                }
            }
        }
        
        return true;
    }
    
    void QuickSort(vector<string>& nums, int begin, int end){
        if(begin >= end){
            return;
        }
        int pivot = begin;
        for(int i=begin+1; i<=end; i++){
            if(larger(nums[pivot], nums[i])){
                if(i == pivot + 1){
                    // Exchange i and pivot
                    string tmp = nums[pivot];
                    nums[pivot] = nums[i];
                    nums[i] = tmp;
                }
                else{
                    // Exchange i and pivot
                    string tmp = nums[pivot];
                    nums[pivot] = nums[i];
                    nums[i] = tmp;
                    // Exchange i and pivot+1
                    tmp = nums[pivot+1];
                    nums[pivot+1] = nums[i];
                    nums[i] = tmp;
                }
                pivot++;
            }
        }
        QuickSort(nums, begin, pivot-1);
        QuickSort(nums, pivot+1, end);
    }
    
    
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        vector<string> nums_str;
        for(int i=0; i<n; i++){
            nums_str.push_back(to_string(nums[i]));
        }
        QuickSort(nums_str, 0, n-1);
        string result;
        for(int i=n-1; i>=0; i--){
            if(nums_str[i] == "0"){
                if(result.length() == 0){
                    if(i > 0){
                        continue;
                    }
                }
            }
            result += nums_str[i];
        }
        return result;
        
    }
};