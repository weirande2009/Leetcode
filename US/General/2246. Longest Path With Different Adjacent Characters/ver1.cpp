#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int dfs(vector<vector<int>>& sons, string& s, int node, int& result){
        vector<int> pathlen;
        for(int child: sons[node]){
            int ret = dfs(sons, s, child, result);
            if(s[node] != s[child]){
                pathlen.push_back(ret);
            }
        }
        int m1 = 0;
        int pos1 = -1;
        int m2 = 0;
        for(int i=0; i<pathlen.size(); i++){
            if(pathlen[i] > m1){
                m1 = pathlen[i];
                pos1 = i;
            }
        }
        if(m1 != 0){
            pathlen[pos1] = 0;
        }
        for(int i=0; i<pathlen.size(); i++){
            m2 = max(m2, pathlen[i]);
        }
        result = max(result, m1+m2+1);
        return max(m1, m2)+1;
    }

    int longestPath(vector<int>& parent, string s) {
        int n = s.length();
        vector<vector<int>> sons(n);
        for(int i=1; i<n; i++){
            sons[parent[i]].push_back(i);
        }
        int result = 0;
        dfs(sons, s, 0, result);
        return result;
    }
};
