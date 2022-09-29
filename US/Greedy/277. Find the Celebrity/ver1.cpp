#include <vector>
using namespace std;

// Algorithm. k[j] means the j person is still possible to be a celebrity. For every person,
// we need to check whether he knows every other possible celebrity. If i doesn't know j, then
// k[j] = false.

/* The knows API is defined for you.
      bool knows(int a, int b); */

bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        vector<bool> k(n, true);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i == j || !k[j]){
                    continue;
                }
                if(!knows(i, j)){
                    k[j] = false;
                }
            }
        }
        for(int i=0; i<n; i++){
            if(k[i]){
                bool flag = true;
                for(int j=0; j<n; j++){
                    if(i == j){
                        continue;
                    }
                    if(knows(i, j)){
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    return i;
                }
            }
        }
        return -1;
    }
};