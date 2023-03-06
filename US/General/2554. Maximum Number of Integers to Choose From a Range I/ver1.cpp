#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> hashtable;
        for(int b: banned){
            hashtable.insert(b);
        }
        int count = 0;
        int sum = 0;
        for(int i=1; i<=n; i++){
            if(hashtable.find(i) == hashtable.end()){
                sum += i;
                if(sum > maxSum){
                    break;
                }
                count++;
            }
        }
        return count;
    }
};