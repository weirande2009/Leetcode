#include <vector>
#include <limits.h>
using namespace std;

class Solution {
public:
    void dfs(vector<int>& price, vector<vector<int>>& special, vector<int>& needs, int n, int k, int& ans){
        if(n == 0){
            ans = min(ans, k);
        }
        if(k >= ans){
            return;
        }
        int mn = 0;
        for(int i=0; i<price.size(); i++){
            mn += price[i]*needs[i];
        }
        ans = min(ans, mn+k);
        for(auto& sp: special){
            bool ok = true;
            int total = 0;
            vector<int> clone = needs;
            for(int i=0; i<sp.size()-1; i++){
                if(sp[i] > needs[i]){
                    ok = false;
                    break;
                }
                clone[i] -= sp[i];
                total += sp[i];
            }
            if(ok){
                dfs(price, special, clone, n-total, k+sp.back(), ans);
            }
        }
    }

    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int n = 0;
        for(int need: needs){
            n += need;
        }
        int ans = INT_MAX;
        dfs(price, special, needs, n, 0, ans);
        return ans;
    }
};
