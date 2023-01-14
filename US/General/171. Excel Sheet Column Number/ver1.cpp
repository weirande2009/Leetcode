#include <string>
using namespace std;

class Solution {
public:
    int titleToNumber(string columnTitle) {
        long long base = 1;
        int col = 0;
        for(int i=columnTitle.length()-1; i>=0; i--){
            col += (columnTitle[i]-'A'+1)*base;
            base *= 26;
        }
        return col;
    }
};
