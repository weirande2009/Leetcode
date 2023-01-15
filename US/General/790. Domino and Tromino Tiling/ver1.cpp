#include <vector>
using namespace std;

class Solution {
public:
    int numTilings(int n) {
        if(n == 1){
            return 1;
        }
        else if(n == 2){
            return 2;
        }
        const int MOD = 1000000007;
        vector<int> f(n+1, 0);
        vector<int> p(n+1, 0);
        f[1] = 1;
        f[2] = 2;
        p[1] = 0;
        p[2] = 1;
        for(int i=3; i<=n; i++){
            p[i] = (f[i-2]+p[i-1])%MOD;
            f[i] = ((f[i-1]+f[i-2])%MOD+(p[i-1]+p[i-1])%MOD)%MOD;
        }
        return f[n];
    }
};
