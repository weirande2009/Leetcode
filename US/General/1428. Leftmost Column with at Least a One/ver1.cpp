#include <bits/stdc++.h>
using namespace std;


// This is the BinaryMatrix's API interface.
// You should not implement it, or speculate about its implementation
class BinaryMatrix {
  public:
    int get(int row, int col);
    vector<int> dimensions();
};


class Solution {

public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> dimension = binaryMatrix.dimensions();
        int ans = INT_MAX;
        for(int i=0; i<dimension[0]; i++){
            int low = 0;
            int high = dimension[1]-1;
            while(low <= high){
                int mid = (low+high) / 2;
                if(binaryMatrix.get(i, mid) == 1){
                    high = mid-1;
                }
                else{
                    low = mid+1;
                }
            }
            if(low < dimension[1] && binaryMatrix.get(i, low) == 1){
                ans = min(ans, low);
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};