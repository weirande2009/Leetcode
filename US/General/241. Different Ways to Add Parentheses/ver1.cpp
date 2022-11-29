#include <vector>
#include <string>
using namespace std;

// Algorithm: dp. Top down, every time solve problem of from start to end in expression

class Solution {
public:
    vector<int> dfs(vector<string>& expression, int start, int end){
        if(start == end){
            return {stoi(expression[start])};
        }
        else{
            vector<int> result;
            for(int i=start; i<=end-2; i+=2){
                // the symbol will be i+1
                vector<int> left = dfs(expression, start, i);
                vector<int> right = dfs(expression, i+2, end);
                for(int j=0; j<left.size(); j++){
                    for(int k=0; k<right.size(); k++){
                        if(expression[i+1] == "+"){
                            result.push_back(left[j]+right[k]);
                        }
                        else if(expression[i+1] == "-"){
                            result.push_back(left[j]-right[k]);
                        }
                        else if(expression[i+1] == "*"){
                            result.push_back(left[j]*right[k]);
                        }
                    }
                }
            }
            return result;
        }        
    }
    
    
    vector<int> diffWaysToCompute(string expression) {
        vector<string> split_expression;
        int begin = 0;
        int l = expression.length();
        for(int i=begin+1; i<l; i++){
            if(expression[i] < '0' || expression[i] > '9'){
                split_expression.push_back(expression.substr(begin, i-begin));
                split_expression.push_back(expression.substr(i, 1));
                begin = i+1;
            }
        }
        split_expression.push_back(expression.substr(begin, -1));
        return dfs(split_expression, 0, split_expression.size()-1);
    }
};