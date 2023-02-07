#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        vector<vector<int>> trees;
        int type = fruits[0];
        int l = 1;
        for(int i=1; i<n; i++){
            if(type != fruits[i]){
                trees.push_back({type, l});
                l = 1;
                type = fruits[i];
            }
            else{
                l++;
            }
        }
        trees.push_back({type, l});
        if(trees.size() == 1){
            return trees[0][1];
        }
        int cur1 = trees[0][0];
        int cur2 = trees[1][0];
        int ans = trees[0][1] + trees[1][1];
        int cur_num = trees[0][1] + trees[1][1];
        for(int i=2; i<trees.size(); i++){
            if(trees[i][0] == cur1 || trees[i][0] == cur2){
                cur_num += trees[i][1];
            }
            else{
                // find the closest in 1 and 2
                if(trees[i-1][0] == cur1){
                    cur2 = trees[i][0];
                }
                else{
                    cur1 = trees[i][0];
                }
                cur_num = trees[i-1][1] + trees[i][1];
            }
            ans = max(ans, cur_num);
        }
        return ans;
    }
};