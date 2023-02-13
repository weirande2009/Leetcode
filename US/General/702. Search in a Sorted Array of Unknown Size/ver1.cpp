#include <bits/stdc++.h>
using namespace std;


// This is the ArrayReader's API interface.
// You should not implement it, or speculate about its implementation
class ArrayReader {
  public:
    int get(int index);
};


class Solution {
public:
    int search(ArrayReader& reader, int target) {
        int low = 0;
        int high = 10000;
        while(low < high){
            int mid = (low+high) / 2;
            int n = reader.get(mid);
            if(n > target){
                high = mid-1;
            }
            else if(n < target){
                low = mid+1;
            }
            else{
                return mid;
            }
        }
        if(reader.get(low) == target){
            return low;
        }
        else if(reader.get(high) == target){
            return high;
        }
        else{
            return -1;
        }
    }
};