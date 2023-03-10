#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dfs(vector<unordered_set<int>>& adj, vector<int>& memo, vector<int>& price, int node, int parent){
        int max_sum = 0;
        for(int child: adj[node]){
            if(child != parent){
                int child_sum = dfs(adj, memo, price, child, node) + price[child];
                max_sum = max(max_sum, child_sum);
            }
        }
        memo[node] = max_sum;
        return max_sum;
    }

    void dfs2(vector<unordered_set<int>>& adj, vector<int>& memo, vector<int>& price, int node, int parent, int& ans, int parent_max_sum){
        int mx1 = 0;
        int mx2 = 0;
        int mc1 = 0;
        // compute the first and second max in children and record the positio of the first max
        for(int child: adj[node]){
            if(child != parent){
                int sum = memo[child] + price[child];
                if(sum > mx1){
                    mx2 = mx1;
                    mx1 = sum;
                    mc1 = child;
                }
                else if(sum > mx2){
                    mx2 = sum;
                }
            }
        }
        ans = max(ans, max(mx1, parent_max_sum));
        
        // search children
        for(int child: adj[node]){
            if(child != parent){
                // if the child is with the max path, we cannot set parent_max_sum as mx1, because they are duplicated
                if(mc1 == child){
                    // set the parent_max_sum as the max between current parent_max_sum and mx2
                    dfs2(adj, memo, price, child, node, ans, max(parent_max_sum, mx2)+price[node]);
                }
                else{
                    dfs2(adj, memo, price, child, node, ans, max(parent_max_sum, mx1)+price[node]);
                }
            }
        }
    }

    long long maxOutput(int n, vector<vector<int>>& edges, vector<int>& price) {
        // record the max for all direct sons for each node
        vector<unordered_set<int>> adj(n);
        vector<int> memo(n);
        for(vector<int>& edge: edges){
            adj[edge[0]].insert(edge[1]);
            adj[edge[1]].insert(edge[0]);
        }
        // dfs from node 0 to make the hashtables for all node
        int sum0 = dfs(adj, memo, price, 0, -1);
        // min must be the value of node 0, so the final cost is just the path sum without the root node value
        int ans = sum0;
        // do dfs2 on all child of node 0
        dfs2(adj, memo, price, 0, -1, ans, 0);
        return ans;
    }
};