#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> s;
        int n = tokens.size();
        for(int i=0; i<n; i++){
            if(tokens[i] == "+"){
                long long a = s.top();
                s.pop();
                long long b = s.top();
                s.pop();
                s.push(a+b);
            }
            else if(tokens[i] == "-"){
                long long a = s.top();
                s.pop();
                long long b = s.top();
                s.pop();
                s.push(b-a);
            }
            else if(tokens[i] == "*"){
                long long a = s.top();
                s.pop();
                long long b = s.top();
                s.pop();
                s.push(a*b);
            }
            else if(tokens[i] == "/"){
                long long a = s.top();
                s.pop();
                long long b = s.top();
                s.pop();
                s.push(b/a);
            }
            else{
                s.push(stoi(tokens[i]));
            }
        }
        return s.top();
    }
};