#include <vector>
#include <stack>
using namespace std;


class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int pushed_index = 0;
        for(int i=0; i<popped.size(); i++){
            bool flag = false;
            // Find in stack
            if(!s.empty() && s.top() == popped[i]){
                flag = true;
                s.pop();
            }
            else{
                for(; pushed_index<pushed.size(); pushed_index++){
                    if(pushed[pushed_index] == popped[i]){
                        flag = true;
                        pushed_index++;
                        break;
                    }
                    s.push(pushed[pushed_index]);
                }
            }
            if(!flag){
                return false;
            }
        }
        return true;
    }
};

int main()
{   
    vector<int> pushed = {1,2,3,4,5};
    vector<int> popped = {4,5,3,2,1};
    Solution s;
    s.validateStackSequences(pushed, popped);


    return 0;
}

