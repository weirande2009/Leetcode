#include <vector>
using namespace std;

// 解题思路
// 利用分治算法


class Solution {
public:
    double myPow(double x, int n) {
        int max_exp = 0;
        int tmp = 1;
        bool negative = false;
        bool overflow = false;
        if(n < 0){
            if(n == -2147483648){
                max_exp = 30;
                overflow = true;
                n += 1;
            }
            n *= -1;
            negative = true;
        }
        else{
            if(n == 2147483647){
                max_exp = 30;
            }
        }
        if(max_exp == 0){
            while(1){ // Compute log2(n)
                if(tmp*2 <= n && tmp*2 > 0){
                    max_exp++;
                    tmp *= 2;
                }
                else{
                    break;
                }
            }
        }
        
        double num = x;
        double num_1 = 1;
        vector<double> exp_x;
        vector<double> exp_2;
        for(int i=0; i<=max_exp; i++){
            exp_x.push_back(num);
            exp_2.push_back(num_1);
            num *= num;
            num_1 *= 2;
        }
        num = 1;
        for(int i=0; i<=max_exp; i++){
            if(n >= exp_2[max_exp-i]){
                n -= exp_2[max_exp-i];
                num *= exp_x[max_exp-i];
            }
        }
        if(overflow){
            num *= x;
        }
        if(negative){
            return 1 / num;
        }
        else{
            return num;
        }
    }
};

int main(){
    Solution s;
    s.myPow(2, -2147483648);


}

