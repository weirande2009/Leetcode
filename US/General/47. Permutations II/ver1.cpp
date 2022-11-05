#include <vector>
#include <unordered_set>
#include <cmath>
using namespace std;

// Algorithm: Use a hashtable to record the added vector. Compute the hash for each vector and
// store in a long long.

class Solution {
public:
    long long hash(vector<int>& cur){
        long long h = 0;
        for(int i=0; i<cur.size(); i++){
            h += pow(21, i)*(cur[i]+10);
        }
        return h;
    }
    
    void dfs(vector<vector<int>>& result, vector<int>& nums, vector<bool>& visited, vector<int>& cur, int layer, int n, unordered_set<long long>& record){
        if(layer == n){
            long long h = hash(cur);
            if(record.find(h) == record.end()){
                record.insert(h);
                result.push_back(cur);
            }
            return;
        }
        for(int i=0; i<n; i++){
            if(!visited[i]){
                visited[i] = true;
                cur.push_back(nums[i]);
                dfs(result, nums, visited, cur, layer+1, n, record);
                cur.erase(cur.begin()+cur.size()-1);
                visited[i] = false;
            }
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> cur;
        int n = nums.size();
        vector<bool> visited(n, false);
        unordered_set<long long> record;
        dfs(result, nums, visited, cur, 0, n, record);
        return result;
    }
};