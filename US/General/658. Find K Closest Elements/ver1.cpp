#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        if(k >= n){
            return arr;
        }
        int low = 0;
        int high = n-1;
        int down;
        int up;
        vector<int> ans;
        while(low <= high){
            int mid = (low+high) / 2;
            if(arr[mid] > x){
                high = mid-1;
            }
            else if(arr[mid] < x){
                low = mid+1;
            }
            else{
                ans.push_back(arr[mid]);
                down = mid-1;
                up = mid+1;
                break;
            }
        }
        if(ans.size() == 0){
            down = low-1;
            up = low;
        }
        while(ans.size() < k){
            if(down < 0){
                ans.push_back(arr[up++]);
            }
            else if(up >= n){
                ans.push_back(arr[down--]);
            }
            else if(x-arr[down] > arr[up] - x){
                ans.push_back(arr[up++]);
            }
            else{
                ans.push_back(arr[down--]);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};