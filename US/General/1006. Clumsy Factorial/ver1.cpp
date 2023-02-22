#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int clumsy(int n) {
        stack<int> s; // for number
        stack<int> ss;  // for symbol
        int sindex = 0;
        s.push(n);
        for(int i=n-1; i>=1; i--){
            if(sindex == 0){
                int result = s.top() * i;
                s.pop();
                s.push(result);
            }
            else if(sindex == 1){
                int result = s.top() / i;
                s.pop();
                s.push(result);
            }
            else{
                s.push(i);
                ss.push(sindex);
            }
            sindex = (sindex+1) % 4;
        }
        stack<int> ns; // for number
        stack<int> nss;  // for symbol
        while(!s.empty()){
            ns.push(s.top());
            s.pop();
        }
        while(!ss.empty()){
            nss.push(ss.top());
            ss.pop();
        }
        while(!nss.empty()){
            int right = ns.top();
            ns.pop();
            int left = ns.top();
            ns.pop();
            if(nss.top() == 0){
                ns.push(left * right);
            }
            else if(nss.top() == 1){
                ns.push(left / right);
            }
            else if(nss.top() == 2){
                ns.push(left + right);
            }
            else{
                ns.push(right - left);
            }
            nss.pop();
        }
        return ns.top();
    }
};