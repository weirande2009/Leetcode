#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<string> ps;
        for(char c: s){
            if(c == '('){
                ps.push("(");
            }
            else{
                if(ps.top() == "("){
                    ps.pop();
                    if(ps.empty() || ps.top() == "("){
                        ps.push("1");
                    }
                    else{
                        int score = stoi(ps.top());
                        ps.pop();
                        ps.push(to_string(score+1));
                    }
                }
                else{
                    int score = stoi(ps.top());
                    ps.pop();
                    ps.pop();
                    if(!ps.empty() && ps.top() != "("){
                        score = score*2 + stoi(ps.top());
                        ps.pop();
                        ps.push(to_string(score));
                    }
                    else{
                        ps.push(to_string(score*2));
                    }
                }
            }
        }
        return stoi(ps.top());
    }
};