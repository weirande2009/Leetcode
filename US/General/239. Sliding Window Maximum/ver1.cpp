#include <vector>
#include <deque>
using namespace std;

//Algorithm: Use a deque. First init the deque with the first window, and "insert" nums[i] to dq.
// The "insert" action consists of three part:
// 1. remove out-of-window index from the front (we insert from back, so the front must be out)
// 2. remove smaller number than nums[i] from back, because for a window, if latter nums[i] with
// larger number will make smaller number useless.
// 3. push back the current number index.
// After insertion, the front of dq must be the largest one.

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // bigger front
        deque<int> dq;
        dq.push_back(0);
        // intialize with the first window
        int m = nums[0];
        for(int i=1; i<k; i++){
            // clean out-window index from front
            while(!dq.empty() && dq.front() < 0){
                dq.pop_front();
            }
            // clean smaller number from back
            while(!dq.empty() && nums[dq.back()] < nums[i]){
                dq.pop_back();
            }
            // push back i
            dq.push_back(i);
            m = max(m, nums[i]);
        }
        vector<int> result;
        result.push_back(m);
        for(int i=k; i<nums.size(); i++){
            int begin = i-k+1;
            // clean out-window index from front
            while(!dq.empty() && dq.front() < begin){
                dq.pop_front();
            }
            // clean smaller number from back
            while(!dq.empty() && nums[dq.back()] < nums[i]){
                dq.pop_back();
            }
            // push back i
            dq.push_back(i);
            result.push_back(nums[dq.front()]);
        }
        return result;
    }
};