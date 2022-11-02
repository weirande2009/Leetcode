#include <vector>
using namespace std;


class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int count = 1;
        int i = 1;
        int j = 0;
        char cur = chars[0];
        while(i < n){
            if(chars[i] == cur){
                count++;
                i++;
            }
            else{
                chars[j] = cur;
                j++;
                if(count != 1){
                    int num = 1;
                    int tmp = count;
                    while(tmp >= 10){
                        num *= 10;
                        tmp /= 10;
                    }
                    while(num > 0){
                        chars[j] = count/num+'0';
                        count %= num;
                        num /= 10;
                        j++;
                    }
                }
                cur = chars[i];
                count = 1;
                i++;
            }
        }
        chars[j] = cur;
        j++;
        if(count != 1){
            int num = 1;
            int tmp = count;
            while(tmp >= 10){
                num *= 10;
                tmp /= 10;
            }
            while(num > 0){
                chars[j] = count/num+'0';
                count %= num;
                num /= 10;
                j++;
            }
        }
        return j;
    }
};