#include <vector>
#include <unordered_map>
using namespace std;

// Algorithm: For a cumulative sum, sum[i]-sum[j] means the sum from i+1 to j.
// So we only need to find the number of sum[i]-sum[j] == k. For each (i, j) that sum[i]-sum[j]=k, 
// there is a valid result. So when facing sum[j], we only need to find the number of sum[j]-k.
// So use a hashtable to store the number of each sum[i].

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> hashtable;
        hashtable[0] = 1;
        int count = 0;
        int sum = 0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            sum += nums[i];
            if(hashtable.find(sum-k) != hashtable.end()){
                count += hashtable[sum-k];
            }
            hashtable[sum]++;
        }
        return count;
    }
};