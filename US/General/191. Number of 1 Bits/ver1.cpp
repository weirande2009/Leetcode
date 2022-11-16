class Solution {
public:
    int hammingWeight(unsigned int n) {
        int count = 0;
        while(n > 0){
            if(n % 2){
                count++;
            }
            n /= 2;
        }
        return count;
    }
};