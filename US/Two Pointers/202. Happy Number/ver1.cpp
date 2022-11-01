#include <vector>
#include <unordered_set>
using namespace std;



class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> hashtable;
        
        while(1){
            if(hashtable.find(n) == hashtable.end()){
                hashtable.insert(n);
            }
            else{
                return false;
            }
            int sum = 0;
            while(n > 0){
                sum += (n % 10)*(n % 10);
                n /= 10;
            }
            if(sum == 1){
                return true;
            }
            n = sum;
        }
        return false;
    }
};