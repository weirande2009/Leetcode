#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>> hashtable;
        for(int i=0; i<n; i++){
            hashtable[arr[i]].push_back(i);
        }
        vector<int> memo(n, INT_MAX);
        queue<int> q;
        q.push(0);
        int step = 0;
        while(!q.empty()){
            queue<int> tmp_q;
            step++;
            while(!q.empty()){
                int p = q.front();
                memo[p] = step;
                if(p == n-1){
                    return step-1;
                }
                if(p-1 >= 0 && memo[p-1] > step){
                    tmp_q.push(p-1);
                }
                if(p+1 < n && memo[p+1] > step){
                    tmp_q.push(p+1);
                }
                for(int i=hashtable[arr[p]].size()-1; i>=0; i--){
                    int next = hashtable[arr[p]][i];
                    if(next != p && memo[next] > step){
                        tmp_q.push(next);
                    }
                }
                // now we can clear the hashtable[arr[p]] because they are useless
                hashtable.erase(arr[p]);
                q.pop();
            }
            q = tmp_q;
        }
        return -1;
    }
};