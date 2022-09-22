#include <cmath>

// 解题思路
// (a+b)%c = (a%c + b%c)%c

class Solution {
public:
    int fib(int n) {
        unsigned int f0 = 0;
        unsigned int f1 = 1;
        unsigned int mod_num = pow(10.0, 9) + 7;
        unsigned int add_result;
        unsigned int tmp;
        unsigned int mod_max = 4294967294 % 1000000007;
        if(n == 0){
            return f0;
        }
        else if(n == 1){
            return f1;
        }
        for(int i=2; i<=n; i++){
            add_result = f0 + f1;
            if(add_result < f0 || add_result < f1){  // 说明相加之后溢出了
                tmp = f1;
                f1 = (add_result + mod_max) % mod_num;
                f0 = tmp;
            } else {
                tmp = f1;
                f1 = add_result % mod_num;
                f0 = tmp;
            }
        }
        return f1;
    }
};

int main(){
    Solution s;
    s.fib(100);
}