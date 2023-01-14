#include <vector>
using namespace std;

class Solution {
public:
    void search(vector<bool>& visited, int pos, int n, int& ans){
        if(pos > n){
            ans++;
            return;
        }
        for(int i=0; i<n; i++){
            if(!visited[i]){
                int num = i+1;
                if(num%pos == 0 || pos%num == 0){
                    visited[i] = true;
                    search(visited, pos+1, n, ans);
                    visited[i] = false;
                }
            }
        }
    }

    int countArrangement(int n) {
        vector<bool> visited(n, 0);
        int result = 0;
        search(visited, 1, n, result);
        return result;
    }
};
