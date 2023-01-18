#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    int minSwaps(vector<int>& data) {
        int n = data.size();
        // compute the number of ones
        int one_num = accumulate(data.begin(), data.end(), 0);
        // we'll compute the sum of each subarray with length of one_num, because finally,
        // there will be a subarray of length one_num with all ones
        int sum = accumulate(data.begin(), data.begin()+one_num, 0);
        int ans = one_num;
        // compute each array and its cost
        for(int i=1; i<=n-one_num; i++){
            if(data[i-1] == 1){
                sum--;
            }
            if(data[i+one_num-1] == 1){
                sum++;
            }
            // the cost is to move other ones outside the array to current array
            ans = min(ans, one_num-sum);
        }
        return ans;
    }
};