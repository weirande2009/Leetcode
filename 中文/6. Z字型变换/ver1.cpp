#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1){
            return s;
        }
        string result;
        for(int i=0; i<numRows; i++){
            int j=0;
            while(1){
                int pos1 = 2*j*(numRows-1)+i, pos2;
                if(i == 0 || i == numRows-1){
                    pos2 = -1;
                }
                else{
                    pos2 = pos1 - 2 * i;
                }
                if(!(i == 0 || i == numRows-1 || j == 0)){
                    if(pos2 < s.length()){
                        result += s[pos2];
                    }
                }
                if(pos1 >= s.length()){
                    break;
                }
                result += s[pos1];
                j++;
            }
        }
        return result;
    }
};

int main(){
    Solution s;
    string a = "A";
    int row = 1;
    string result = s.convert(a, row);
    cout << result << endl;
    return 0;
}