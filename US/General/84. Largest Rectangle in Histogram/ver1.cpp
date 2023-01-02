#include <vector>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> less_from_left(n, -1);
        vector<int> less_from_right(n, n);

        // compute less from left
        for(int i=1; i<n; i++){
            int p = i-1;
            while(p >= 0 && heights[p] >= heights[i]){
                // jump to find the first less
                p = less_from_left[p];
            }
            less_from_left[i] = p;
        }
        // compute less from right
        for(int i=n-2; i>=0; i--){
            int p = i+1;
            while(p < n && heights[p] >= heights[i]){
                // jump to find the first less
                p = less_from_right[p];
            }
            less_from_right[i] = p;
        }
        int result = 0;
        for(int i=0; i<n; i++){
            result = max(result, heights[i] * (less_from_right[i] - less_from_left[i] - 1));
        }
        return result;
    }
};