#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        // from left to right
        int carry = 1;
        for(int i=n-1; i>=0; i--){
            digits[i] += carry;
            if(digits[i] >= 10){
                carry = 1;
                digits[i] -= 10;
            }
            else{
                carry = 0;
            }
        }
        if(carry == 1){
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};