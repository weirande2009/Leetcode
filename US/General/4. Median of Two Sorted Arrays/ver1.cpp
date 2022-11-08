#include <vector>
using namespace std;

// Algorithm: write a function to get the next int

class Solution {
public:
    int i1 = 0;
    int i2 = 0;
    int l1;
    int l2;
    int nextInt(vector<int>& nums1, vector<int>& nums2){
        if(i1 == l1){
            return nums2[i2++];
        }
        if(i2 == l2){
            return nums1[i1++];
        }
        if(nums1[i1] > nums2[i2]){
            i2++;
            return nums2[i2-1];
        }
        else{
            i1++;
            return nums1[i1-1];
        }
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        l1 = nums1.size();
        l2 = nums2.size();
        int count = 0;
        int median1, median2;
        int target = (l1+l2+1)/2;
        while(1){
            int next = nextInt(nums1, nums2);
            count++;
            if(count == target){
                median1 = next;
                if((l1+l2)%2 == 0){
                    median2 = nextInt(nums1, nums2);
                }
                break;
            }
        }
        if((l1+l2)%2){
            return median1;
        }
        else{
            return (median1+median2) / 2.0;
        }
    }
};