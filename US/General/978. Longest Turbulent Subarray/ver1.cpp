#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int begin = -1;
        int mode = -1;  // 0 means first >, 1 means first <, -1 there is no
        int n = arr.size();
        int ans = 1;
        for(int i=1; i<n; i++){
            if(mode == -1){
                if(arr[i] > arr[i-1]){
                    mode = 0;
                    begin = i-1;
                    ans = max(ans, i-begin+1);
                }
                else if(arr[i] < arr[i-1]){
                    mode = 1;
                    begin = i-1;
                    ans = max(ans, i-begin+1);
                }
            }
            else if(mode == 0){
                if((i-begin)%2 == 0){  // change
                    if(arr[i] >= arr[i-1]){  // not follow
                        ans = max(ans, i-begin);
                        mode = -1;
                        i--;
                    }
                    else{
                        ans = max(ans, i-begin+1);
                    }
                }
                else{  // not change
                    if(arr[i] <= arr[i-1]){  // not follow
                        ans = max(ans, i-begin);
                        mode = -1;
                        i--;
                    }
                    else{
                        ans = max(ans, i-begin+1);
                    }
                }
            }
            else{
                if((i-begin)%2 == 0){  // change
                    if(arr[i] <= arr[i-1]){  // not follow
                        ans = max(ans, i-begin);
                        mode = -1;
                        i--;
                    }
                    else{
                        ans = max(ans, i-begin+1);
                    }
                }
                else{  // not change
                    if(arr[i] >= arr[i-1]){  // not follow
                        ans = max(ans, i-begin);
                        mode = -1;
                        i--;
                    }
                    else{
                        ans = max(ans, i-begin+1);
                    }
                }
            }
        }
        return ans;
    }
};