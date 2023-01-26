#include <vector>
using namespace std;

class Solution {
public:
    int longestMountain(vector<int>& arr) {
        arr.push_back(100000);
        int n = arr.size();
        int begin = -1;
        int ans = 0;
        bool up = false;
        for(int i=1; i<n; i++){
            if(arr[i] > arr[i-1]){
                if(begin == -1){
                    up = true;
                    begin = i-1;
                }
                else if(!up){
                    if(i-begin > 2){
                        ans = max(ans, i-begin);
                    }
                    begin = i-1;
                    up = true;
                }
            }
            else if(arr[i] < arr[i-1]){
                if(begin != -1){
                    up = false;
                }
            }
            else{
                if(begin != -1){
                    if(i-begin > 2 && !up){
                        ans = max(ans, i-begin);
                    }
                    begin = -1;
                }
                
            }
        }
        return ans;
    }
};