#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// Algorithm. Use s1+s2 < s2+s1 to judge the relationship of s1 and s2.


class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        vector<string> nums_str;
        for(int i=0; i<n; i++){
            nums_str.push_back(to_string(nums[i]));
        }
        sort(begin(nums_str), end(nums_str), [](string &s1, string &s2){ return s1+s2<s2+s1; });
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