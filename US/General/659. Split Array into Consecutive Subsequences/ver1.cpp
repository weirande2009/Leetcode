#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        // key means the end of the consecutive sequence and value means the length of the sequences
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> hashtable;
        hashtable[nums[0]].push(1);
        int n = nums.size();
        for(int i=1; i<n; i++){
            if(hashtable.find(nums[i]-1) != hashtable.end()){  // if we can find the previous
                int length = hashtable[nums[i]-1].top();
                hashtable[nums[i]-1].pop();
                if(hashtable[nums[i]-1].empty()){
                    hashtable.erase(nums[i]-1);
                }
                hashtable[nums[i]].push(length+1);
            }
            else{
                hashtable[nums[i]].push(1);
            }
        }
        // make sure that each sequence's length is greater than 2
        for(auto& [end, pq]: hashtable){
            while(!pq.empty()){
                if(pq.top() < 3){
                    return false;
                }
                pq.pop();
            }
        }
        return true;
    }
};