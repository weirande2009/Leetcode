#include <vector>
using namespace std;

// Algorithm: O(n^2), when meet n duplicate number, move the left number forward.

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1){
            return n;
        }
        int d = 0;
        for(int i=0; i<n-d-1; i++){\
            int tmp = nums[i];
            int tmp_d = 0;
            while(nums[i+1+tmp_d] == tmp){
                tmp_d++;
                if(i+1+tmp_d >= n){
                    break;
                }
            }
            if(tmp_d > 0){
                d += tmp_d;
                for(int j=i; j<n-tmp_d; j++){
                    nums[j] = nums[j+tmp_d];
                }
                for(int j=0; j<tmp_d; j++){
                    nums[n-j-1] = tmp;
                }
            }
        }
        return n-d;
    }
};

int main(){
    Solution s;
    vector<int> v = {0,0,1,1,1,2,2,3,3,4};
    s.removeDuplicates(v);

    return 0;
}


