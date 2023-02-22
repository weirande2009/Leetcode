#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool judgeTotallyDifferent(const vector<int>& v1, const vector<int>& v2){
        int n = v1.size();
        for(int i=0; i<n; i++){
            if(v1[i] == v2[i]){
                return false;
            }
        }
        return true;
    }

    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // Let's say i-th row is the all zero after some flips, then there is another j-th row is
        // also all zero, then i-th and j-th are the same before any flip. If there is another k-th
        // row is all one, then i-th and k-th row are totally different before any flip.
        // Thus, this problem is transformed to the problem to find a row with most the same or totally
        // different rows.
        int count = 0;
        for(int i=0; i<n; i++){
            int c = 0;
            for(int j=0; j<n; j++){
                if(matrix[i] == matrix[j] || judgeTotallyDifferent(matrix[i], matrix[j])){
                    c++;
                }
            }
            count = max(c, count);
        }
        return count;
    }
};