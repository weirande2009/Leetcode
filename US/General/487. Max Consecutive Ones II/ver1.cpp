#include <vector>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return 1;
        }
        vector<int> record;
        int count = 1;
        int cur = nums[0];
        bool has_zero = false;
        if(cur == 0){
            record.push_back(0);
            has_zero = true;
        }
        for(int i=1; i<n; i++){
            if(nums[i] != cur){
                record.push_back(count);
                cur = nums[i];
                count = 1;
            }
            else{
                count++;
            }
            if(nums[i] == 0){
                has_zero = true;
            }
        }
        if(cur == 1){
            record.push_back(count);
        }
        if(!has_zero){
            return n;
        }
        int result = record[0]+1;
        for(int i=2; i<record.size(); i+=2){
            if(record[i-1] == 1){
                result = max(result, record[i]+1+record[i-2]);
            }
            else{
                result = max(result, record[i]+1);
            }
        }
        return result;
    }
};
