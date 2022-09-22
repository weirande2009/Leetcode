#include <string>
#include <stack>
using namespace std;

// Algorithm: O(n), Use stack to store all the left, when meeting right, the top of stack
// must match the right part.

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0; i<s.length(); i++){
            if(s[i] == '('){
                st.push(')');
            }
            else if(s[i] == '['){
                st.push(']');
            }
            else if(s[i] == '{'){
                st.push('}');
            }
            else{
                if(st.empty()){
                    return false;
                }
                if(st.top() == s[i]){
                    st.pop();
                }
                else{
                    return false;
                }
            }
        }
        if(st.empty()){
            return true;
        }
        else{
            return false;
        }
    }
};

int main(){
    string str = "()";
    Solution s;
    s.isValid(str);


}