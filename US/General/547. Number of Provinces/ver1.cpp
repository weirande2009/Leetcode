#include <vector>
#include <queue>
using namespace std;

class Solution {
public:

    int findCircleNum(vector<vector<int>>& isConnected) {
        int count = 0;
        int n = isConnected.size();
        vector<bool> visited(n, false);
        queue<int> q;
        for(int i=0; i<n; i++){
            if(!visited[i]){
                count++;
                q.push(i);
                while(!q.empty()){
                    int pos = q.front();
                    visited[pos] = true;
                    for(int j=0; j<n; j++){
                        if(isConnected[pos][j] && !visited[j]){
                            q.push(j);
                        }
                    }
                    q.pop();
                }
            }
        }
        return count;
    }
};