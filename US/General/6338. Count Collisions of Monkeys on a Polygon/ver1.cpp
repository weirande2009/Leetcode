#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;

class Solution {
public:
    int monkeyMove(int n) {
        const int MOD = 1000000007;
        unordered_map<long long, long long> hashtable;
        unordered_map<long long, long long> ht;
        long long ans = 2;
        long long r = 1;
        ht[0] = 1;
        hashtable[0] = ans;
        int times = log2(n);
        for(int i=1; i<=times; i++){
            ans = (ans*ans) % MOD;
            r *= 2;
            ht[i] = r;
            hashtable[i] = ans;
        }
        ans = 1;
        while(n > 1){
            int t = log2(n);
            ans = (ans*hashtable[t]) % MOD;
            n -= ht[t];
        }
        if(n == 1){
            ans = (ans*2) % MOD;
        }
        return (ans-2+MOD) % MOD;
    }
};
