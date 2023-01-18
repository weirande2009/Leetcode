#include <vector>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int begin = matrix[0][0];
        int end = matrix[n-1][n-1];
        while(begin < end){
            int mid = begin + (end - begin) / 2;
            vector<int> smallLargePair = {matrix[0][0], matrix[n-1][n-1]};
            int j = findNumSmallerThanK(matrix, mid, smallLargePair);
            if(j == k){
                return smallLargePair[0];
            }
            else if(j < k){
                begin = smallLargePair[1];
            }
            else{
                end = smallLargePair[0];
            }
        }
        return begin;
    }

    int findNumSmallerThanK(vector<vector<int>>& matrix, int k, vector<int>& smallLargePair){
        int count = 0;
        int n = matrix.size();
        int row = n-1;
        int col = 0;
        while(row >=0 && col < n){
            if(matrix[row][col] > k){
                smallLargePair[1] = min(smallLargePair[1], matrix[row][col]);
                row--;
            }
            else{
                smallLargePair[0] = max(smallLargePair[0], matrix[row][col]);
                count += row+1;
                col++;
            }
        }
        return count;
    }
};