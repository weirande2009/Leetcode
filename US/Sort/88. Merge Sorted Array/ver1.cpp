#include <vector>
using namespace std;

// Algorithm: O(n). From back to front, set i=m-1, j=n-1, and l=0. Set the larger one to
// the back of nums1 array, and judge the next.


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1;
        int j = n-1;
        int l = 0;
        while(l < m+n){
            if(i < 0){
                for(int k=0; k<=j; k++){
                    nums1[k] = nums2[k];
                    l++;
                }
            }
            else if(j < 0){
                for(int k=0; k<=i; k++){
                    nums1[k] = nums1[k];
                    l++;
                }
            }
            else{
                if(nums2[j] >= nums1[i]){
                    nums1[m+n-l-1] = nums2[j];
                    j--;
                }
                else{
                    nums1[m+n-l-1] = nums1[i];
                    i--;
                }
                l++;
            }
        }
    }
};
