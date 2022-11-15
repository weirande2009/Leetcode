#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        if(n < 4){
            return n-1;
        }
        if(n == 4){
            return n;
        }
        unordered_map<int, int> hashtable;
        hashtable[3] = 3;
        hashtable[4] = 4;
        hashtable[5] = 6;
        int n3 = n / 3 - 1;
        int left = n % 3 + 3;
        return pow(3, n3)*hashtable[left];
        
    }
};
