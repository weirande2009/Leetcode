#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> dp(n+1, 0);
        unordered_set<int> who_trust;
        for(auto& v: trust){
            dp[v[1]]++;
            who_trust.insert(v[0]);
        }
        for(int i=1; i<=n; i++){
            if(dp[i] == n-1 && who_trust.find(i) == who_trust.end()){
                return i;
            }
        }
        return -1;
    }
};
