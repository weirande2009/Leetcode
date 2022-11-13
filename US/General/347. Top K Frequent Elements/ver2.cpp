#include <vector>
#include <unordered_map>
using namespace std;

// Algorithm: when choosing the pivot, use random

class Solution {
public:
    void swap(vector<int>& v1, vector<int>& v2){
        int tmp = v1[0];
        v1[0] = v2[0];
        v2[0] = tmp;
        tmp = v1[1];
        v1[1] = v2[1];
        v2[1] = tmp;
    }
    
    int search(vector<vector<int>>& nums, int begin, int end){
        int pivot = begin + rand() % (end - begin + 1);
        swap(nums[begin], nums[pivot]);
        pivot = begin;
        int i = begin+1;
        int j = end;
        while(i <= j){
            if(nums[pivot][1] < nums[i][1]){
                swap(nums[i], nums[j]);
                j--;
            }
            else{
                i++;
            }
        }
        swap(nums[pivot], nums[j]);
        return j;
    }
    
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
        vector<vector<int>> freq;
        for(const auto& a: hashtable){
            freq.push_back({a.first, a.second});
        }
        int n = freq.size();
        int low = 0;
        int high = n-1;
        vector<int> result;
        while(1){
            int s = search(freq, low, high);
            if(s < n-k){
                low = s+1;
            }
            else if(s > n-k){
                high = s-1;
            }
            else{
                for(int i=s; i<n; i++){
                    result.push_back(freq[i][0]);
                }
                return result;
            }
        }
        return {};
    }
};