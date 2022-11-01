#include <vector>
#include <unordered_set>
using namespace std;



class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        unordered_set<int> s1;
        unordered_set<int> s2;
        for(int i=0; i<n; i++){
            s1.insert(nums1[i]);
        }
        for(int i=0; i<m; i++){
            s2.insert(nums2[i]);
        }
        vector<int> result;
        for(int i: s1){
            if(s2.find(i) != s2.end()){
                result.push_back(i);
            }
        }
        return result;
        
    }
};