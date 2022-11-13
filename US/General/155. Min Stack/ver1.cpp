#include <stack>
using namespace std;

// Algorithm: Use a stack to record the current minimum number. Thee lower smaller number will
// make higher bigger number useless. So we only push smaller or equal number to min_s.

class MinStack {
private:
    stack<int> s;
    stack<int> min_s;
    
public:
    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        if(min_s.empty() || min_s.top() >= val){
            min_s.push(val);
        }
    }
    
    void pop() {
        if(min_s.top() == s.top()){
            min_s.pop();
        }
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return min_s.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */