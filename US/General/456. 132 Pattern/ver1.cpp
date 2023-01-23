#include <vector>
#include <stack>
#include <limits.h>
using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        // smallest[i] means the smallest number till nums[i]
        vector<int> smallest;
        int mn = INT_MAX;
        for(int num: nums){
            mn = min(mn, num);
            smallest.push_back(mn);
        }
        // st.top() means the smallest number from back
        stack<int> st;
        for(int i=n-1; i>=0; i--){
            // if the current number is at least bigger than one number before
            if(nums[i] > smallest[i]){
                // find the first one in stack which is smaller than current number and bigger than the smallest till now
                while(!st.empty() && nums[i] > st.top()){
                    if(smallest[i] < st.top()){
                        return true;
                    }
                    st.pop();
                }
                if(st.empty() || nums[i] < st.top()){ // if the current number is smaller than the biggest from back, push it
                    st.push(nums[i]);
                }
            }
        }
        return false;
    }
};