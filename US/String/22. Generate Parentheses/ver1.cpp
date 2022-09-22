#include <vector>
#include <string>
using namespace std;

// Algorithm: Use recursion as a depth-first traverse and each time, we need to check whether 
// left number is not smaller than right number.

class Solution {
public:
    void Recursion(vector<string>& result, string pre_str, int n, int layer, int left){
        if(layer == 2*n){
            result.push_back(pre_str);
            return;
        }
        if(left < n){
            Recursion(result, pre_str+'(', n, layer+1, left+1);
        }
        if(layer-left < left){
            Recursion(result, pre_str+')', n, layer+1, left);
        }
    }
    
    
    
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        Recursion(result, "", n, 0, 0);
        return result;
    }
};