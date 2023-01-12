#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int dfs(int n, unordered_map<int, vector<int>>& hashtable, vector<bool>& hasApple, vector<bool>& visited, int i){
        if(hashtable.find(i) == hashtable.end()){
            return 0;
        }
        visited[i] = true;
        int sum = 0;
        for(auto& son: hashtable[i]){
            if(!visited[son]){
                int result = dfs(n, hashtable, hasApple, visited, son);
                if(result != 0 || hasApple[son]){
                    result += 2;
                }
                sum += result;
            }
        }
        return sum;
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        unordered_map<int, vector<int>> hashtable;
        vector<bool> visited(edges.size(), false);
        for(auto& edge: edges){
            hashtable[edge[0]].push_back(edge[1]);
            hashtable[edge[1]].push_back(edge[0]);
        }
        return dfs(n, hashtable, hasApple, visited, 0);
    }
};