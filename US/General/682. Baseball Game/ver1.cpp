#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> s;
        for(const string& operation: operations){
            if(operation == "+"){
                int s1 = s.top();
                s.pop();
                int s2 = s.top();
                s.push(s1);
                s.push(s1+s2);
            }
            else if(operation == "D"){
                int s1 = s.top();
                s.push(s1*2);
            }
            else if(operation == "C"){
                s.pop();
            }
            else{
                s.push(stoi(operation));
            }
        }
        int sum = 0;
        while(!s.empty()){
            sum += s.top();
            s.pop();
        }
        return sum;
    }
};