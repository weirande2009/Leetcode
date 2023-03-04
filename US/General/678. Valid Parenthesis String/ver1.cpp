#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        stack<char> st;
        for(char c: s){
            if(c == '(' || c == '*'){
                st.push(c);
            }
            else if(c == ')'){
                if(st.empty()){
                    return false;
                }
                else if(st.top() == '('){
                    st.pop();
                }
                else if(st.top() == '*'){
                    int count_star = 0;
                    while(!st.empty() && st.top() == '*'){
                        count_star++;
                        st.pop();
                    }
                    if(!st.empty()){
                        st.pop();
                    }
                    else{
                        count_star--;
                    }
                    for(int i=0; i<count_star; i++){
                        st.push('*');
                    }
                }
                else{
                    return false;
                }
            }
        }
        int count = 0;
        while(!st.empty()){
            if(st.top() == '*'){
                count++;
            }
            else{
                count--;
            }
            if(count < 0){
                return false;
            }
            st.pop();
        }
        return true;
    }
};