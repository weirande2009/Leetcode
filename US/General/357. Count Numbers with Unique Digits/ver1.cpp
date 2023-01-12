class Solution {
public:
    int factorial(int n, int r){
        int a = 1;
        for(int i=r; i>r-n; i--){
            a *= i;
        }
        return a;
    }

    int countNumbersWithUniqueDigits(int n) {
        int count = 1;
        for(int i=1; i<=n; i++){
            count += 9 * factorial(i-1, 9);
        }
        return count;
    }
};