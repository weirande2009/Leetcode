#include <stack>
using namespace std;

// 解题思路
// 用一个栈作为入栈，一个作为出栈，当插入时，直接加入到入栈中，当删除时，从出栈中删除，若出栈为空，
// 则将入栈中的元素由顶向下一个一个地加入到出栈中，这样就实现了队列的功能

class CQueue {
private:
    stack<int> in_stack, out_stack;

public:
    CQueue() {

    }
    
    void appendTail(int value) {
        in_stack.push(value);
    }
    
    int deleteHead() {
        if(out_stack.empty()){
            while(1){
                if(in_stack.empty()){
                    break;
                }
                out_stack.push(in_stack.top());
                in_stack.pop();
            }
        }
        if(out_stack.empty()){
            return -1;
        }
        int top = out_stack.top();
        out_stack.pop();
        return top;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */