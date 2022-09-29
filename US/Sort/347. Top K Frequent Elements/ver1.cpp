#include <vector>
#include <unordered_map>
using namespace std;

// Algorithm: First, record the number of all the numbers. Create a 2d array which contain the 
// numbers in nums and corresponding number. The first the largest k number in the 2d array.

class Solution {
public:
    void swap(vector<int>& i, vector<int>& j){
        int tmp = i[0];
        i[0] = j[0];
        j[0] = tmp;
        
        tmp = i[1];
        i[1] = j[1];
        j[1] = tmp;
    }
    
    int partition(vector<vector<int>>& nums, int begin, int end){
        int j = begin;
        int i = begin;
        while(j < end){
            if(nums[j][1] < nums[end][1]){
                swap(nums[i], nums[j]);
                i++;
            }
            j++;
        }
        swap(nums[i], nums[end]);
        return i;
    }
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> hashtable;
        for(int i=0; i<n; i++){
            auto f = hashtable.find(nums[i]);
            if(f == hashtable.end()){
                hashtable[nums[i]] = 1;
            }
            else{
                hashtable[nums[i]]++;
            }
        }
        // 
        vector<vector<int>> pair;
        for(auto p: hashtable){
            pair.push_back({p.first, p.second});
        }
        int n_p = pair.size();
        int left = 0;
        int right = n_p-1;
        k = n_p-k;
        while(1){
            int p = partition(pair, left, right);
            if(p < k){
                left = p+1;
            }
            else if(p > k){
                right = p-1;
            }
            else{
                break;
            }
        }
        vector<int> result;
        for(int i=k; i<n_p; i++){
            result.push_back(pair[i][0]);
        }
        return result;
    }
};