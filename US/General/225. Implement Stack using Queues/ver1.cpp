#include <bits/stdc++.h>
using namespace std;

class MyStack {
private:
    queue<int> q1;
    queue<int> q2;
    int sign;

public:
    MyStack() {
        sign = 1;
    }
    
    void push(int x) {
        if(sign == 1){
            q1.push(x);
        }
        else{
            q2.push(x);
        }
    }
    
    int pop() {
        int ans;
        if(sign == 1){
            while(q1.size() > 1){
                q2.push(q1.front());
                q1.pop();
            }
            ans = q1.front();
            q1.pop();
        }
        else{
            while(q2.size() > 1){
                q1.push(q2.front());
                q2.pop();
            }
            ans = q2.front();
            q2.pop();
        }
        sign *= -1;
        return ans;
    }
    
    int top() {
        int ans;
        if(sign == 1){
            while(q1.size() > 1){
                q2.push(q1.front());
                q1.pop();
            }
            ans = q1.front();
        }
        else{
            while(q2.size() > 1){
                q1.push(q2.front());
                q2.pop();
            }
            ans = q2.front();
        }
        return ans;
    }
    
    bool empty() {
        return q1.empty() && q2.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */