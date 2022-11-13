#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hashtable;
        for(int i=0; i<nums.size(); i++){
            if(hashtable.find(nums[i]) == hashtable.end()){
                hashtable[nums[i]] = 1;
            }
            else{
                hashtable[nums[i]]++;
            }
        }
        auto cmp = [](const vector<int>& v1, const vector<int>& v2){return v1[1] > v2[1];};
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
        for(const auto& a: hashtable){
            pq.push({a.first, a.second});
            if(pq.size() > k){
                pq.pop();
            }
        }
        vector<int> result;
        int i = 0;
        while(i < k){
            result.push_back(pq.top()[0]);
            pq.pop();
            i++;
        }
        return result;
    }
};