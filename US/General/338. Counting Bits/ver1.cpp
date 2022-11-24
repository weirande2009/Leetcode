#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result(n+1, 0);
        for(int i=0; i<=n; i++){
            int count = 0;
            int num = i;
            while(num > 0){
                if(num%2){
                    count++;
                }
                num /= 2;
            }
            result[i] = count;
        }
        return result;
    }
};