#include <vector>
using namespace std;


// Algorithm: Use two pointer, one on left and one on right. 


class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int max_area = 0;
        int left_p = 0;
        int right_p = n - 1;
        while(1){
            int side = height[left_p] > height[right_p] ? height[right_p] : height[left_p];
            if(side*(right_p-left_p) > max_area){
                max_area = side*(right_p-left_p);
            }
            if(height[left_p] > height[right_p]){
                right_p--;
            }
            else{
                left_p++;
            }
            if(right_p == left_p){
                break;
            }
        }
        return max_area;
    }
};