#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(unordered_map<int, unordered_map<int, int>>& tree, int layer, int pos, int sum, int& ans){
        sum += tree[layer][pos];
        // find sons
        bool has_sons = false;
        int left_son = pos*2-1;
        int right_son = pos*2;
        if(tree.find(layer+1) != tree.end()){
            if(tree[layer+1].find(left_son) != tree[layer+1].end()){
                dfs(tree, layer+1, left_son, sum, ans);
                has_sons = true;
            }
            if(tree[layer+1].find(right_son) != tree[layer+1].end()){
                dfs(tree, layer+1, right_son, sum, ans);
                has_sons = true;
            }
        }
        if(!has_sons){  // leaves, so add to the answer
            ans += sum;
        }
    }

    int pathSum(vector<int>& nums) {
        unordered_map<int, unordered_map<int, int>> tree;
        for(int num: nums){
            int layer = num / 100;
            int pos = num % 100 / 10;
            int value = num % 10;
            tree[layer][pos] = value;
        }
        int ans = 0;
        dfs(tree, 1, 1, 0, ans);
        return ans;
    }
};