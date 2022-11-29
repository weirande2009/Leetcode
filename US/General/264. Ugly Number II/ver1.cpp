#include <vector>
using namespace std;

class Solution {
public:
    vector<int> ugly;
    
    int nthUglyNumber(int n) {
        ugly = vector<int>(1690, 0);
        ugly[0] = 1;
        // use three pointers
        int p2 = 0;
        int p3 = 0;
        int p5 = 0;
        for(int i=1; i<1690; i++){
            int mn = min(ugly[p2]*2, min(ugly[p3]*3, ugly[p5]*5));
            ugly[i] = mn;
            // all pointers will move on when the min is the same as the corresponding number
            if(mn == ugly[p2]*2){
                p2++;
            }
            if(mn == ugly[p3]*3){
                p3++;
            }
            if(mn == ugly[p5]*5){
                p5++;
            }
        }
        return ugly[n-1];
    }
};