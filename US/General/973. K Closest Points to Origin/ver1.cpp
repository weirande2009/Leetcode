#include <vector>
using namespace std;

class Solution {
public:
    void swap(vector<int>& v1, vector<int>& v2){
        int tmp = v1[0];
        v1[0] = v2[0];
        v2[0] = tmp;
        tmp = v1[1];
        v1[1] = v2[1];
        v2[1] = tmp;
    }
    
    int binarySearch(vector<vector<int>>& distance, int left, int right){
        int i=left+1;  // current pointer
        int j=right;  // current exchange position
        while(i <= j){
            if(distance[i][0] > distance[left][0]){
                swap(distance[i], distance[j]);
                j--;
            }
            else{
                i++;
            }
        }
        swap(distance[j], distance[left]);
        return j;
    }
    
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        vector<vector<int>> distance;
        for(int i=0; i<n; i++){
            distance.push_back({points[i][0]*points[i][0]+points[i][1]*points[i][1], i});
        }
        int low = 0;
        int high = n-1;
        // binary sort to find the K smallest points
        while(low < high){
            int m = binarySearch(distance, low, high);
            if(m < k){
                low = m+1;
            }
            else if(m > k){
                high = m-1;
            }
            else{
                break;
            }
        }
        vector<vector<int>> result;
        for(int i=0; i<k; i++){
            result.push_back(points[distance[i][1]]);
        }
        return result;
    }
};