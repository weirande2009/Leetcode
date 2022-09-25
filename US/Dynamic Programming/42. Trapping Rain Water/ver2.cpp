#include <vector>
using namespace std;

// Algorithm: O(n). From i = 0 to n-1, first record left wall index. Find the first height[i]
// that height[i] >= left wall. In this progress, sum the middle heights. Then, the amount of 
// water between [left, i] is height[left]*(left-i-1)-sum(middle). Then, set left=i and continue
// searching. For highest wall, there is no higher height. So we start from n-1 to the highest wall.
// The progress is the same as left to right.

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0;
        int right = n-1;
        // Forward
        int left_wall_index = 0;
        int middle_sum = 0;
        int volumn = 0;
        for(int i=1; i<n; i++){
            if(height[i] >= height[left_wall_index]){
                volumn += height[left_wall_index] * (i-left_wall_index-1) - middle_sum;
                left_wall_index = i;
                middle_sum = 0;
            }
            else{
                middle_sum += height[i];
            }
        }
        // Backward
        int right_wall_index = n-1;
        middle_sum = 0;
        for(int i=n-2; i>=left_wall_index; i--){
            if(height[i] >= height[right_wall_index]){
                volumn += height[right_wall_index] * (right_wall_index-i-1) - middle_sum;
                right_wall_index = i;
                middle_sum = 0;
            }
            else{
                middle_sum += height[i];
            }
        }
        return volumn;
    }
};