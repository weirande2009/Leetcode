#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;


class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> hashtable;
        for(int i=0; i<tasks.size(); i++){
            hashtable[tasks[i]]++;
        }
        vector<int> nums;
        for(auto& a: hashtable){
            nums.push_back(a.second);
        }
        sort(nums.begin(), nums.end(), greater<int>());
        // idle_num initialized as the max number of possible idle slot for tasks except the one
        // with the largest number
        int idle_num = (nums[0] - 1) * n;
        int m = nums.size();
        // greedy
        for(int i=1; i<m && idle_num > 0; i++){
            // if nums[i] == nums[0], the extra one can be put after the last nums[i]
            idle_num -= min(nums[0] - 1, nums[i]);
        }
        idle_num = max(idle_num, 0);
        return idle_num + tasks.size();
    }
};