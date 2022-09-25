#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int volumn = 0;
        while(1){
            int last_wall = -1;
            bool higher = false;
            for(int i=0; i<n; i++){
                if(height[i] > 0){
                    higher = true;
                    if(last_wall == -1){ // first wall
                        last_wall = i;
                    }
                    else{
                        volumn += i-last_wall-1;
                        last_wall = i;
                    }
                    height[i]--;
                }
            }
            if(!higher){
                break;
            }
        }
        return volumn;
    }
};