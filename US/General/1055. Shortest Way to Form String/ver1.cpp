#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestWay(string source, string target) {
        int n = target.size();
        int l = source.size();
        int count = 1;
        int j = 0;
        for(int i=0; i<n; i++){
            int k = 0;
            while(1){
                k++;
                if(source[j++] == target[i]){
                    break;
                }
                if(k >= l){
                    return -1;
                }
                if(j >= l){
                    count++;
                    j = 0;
                }
            }
        }
        return count;
    }
};