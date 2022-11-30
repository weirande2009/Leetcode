#include <vector>
#include <unordered_map>
#include <limits.h>
using namespace std;

// almost the same as ugly number II, but use a hashtable to record each pointer of primes

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        unordered_map<int, int> hashtable;
        for(int p: primes){
            hashtable[p] = 0;
        }
        vector<long long> ugly = {1};
        for(int i=1; i<n; i++){
            long long num = INT_MAX;
            for(auto a: hashtable){
                num = min(num, ugly[a.second]*a.first);
            }
            for(auto& a: hashtable){
                if(num == ugly[a.second]*a.first){
                    a.second++;
                }
            }
            ugly.push_back(num);
        }
        return ugly[n-1];
    }
};