#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        // gt[i] means the number of rating that are greater than rating[i] after i
        vector<int> gt(n, 0);
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(rating[j] > rating[i]){
                    gt[i]++;
                }
            }

        }
        // lt[i] means the number of rating that are less than rating[i] after i
        vector<int> lt(n, 0);
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(rating[j] < rating[i]){
                    lt[i]++;
                }
            }
        }
        int count = 0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(rating[j] > rating[i]){
                    count += gt[j];
                }
                if(rating[j] < rating[i]){
                    count += lt[j];
                }
            }
        }
        return count;
    }
};