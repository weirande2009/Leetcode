#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& result, vector<int>& cur, unordered_set<int>& left){
        if(left.size() == 0){
            result.push_back(cur);
            return;
        }
        vector<int> tmp;
        for(int i: left){
            tmp.push_back(i);
        }
        for(int i=0; i<tmp.size(); i++){
            left.erase(tmp[i]);
            cur.push_back(tmp[i]);
            dfs(result, cur, left);
            left.insert(tmp[i]);
            cur.erase(cur.begin()+cur.size()-1);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> cur;
        unordered_set<int> left;
        for(int i=0; i<nums.size(); i++){
            left.insert(nums[i]);
        }
        dfs(result, cur, left);
        return result;
    }
};