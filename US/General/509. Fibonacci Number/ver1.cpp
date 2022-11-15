class Solution {
public:
    int fib(int n) {
        if(n < 2){
            return n;
        }
        int f0 = 0;
        int f1 = 1;
        for(int i=2; i<=n; i++){
            f1 += f0;
            f0 = f1-f0;
        }
        return f1;
    }
};