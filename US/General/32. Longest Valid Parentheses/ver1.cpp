#include <stack>
#include <vector>
#include <string>
using namespace std;

// Algorithm: Use a stack to record the index of each '('. Use a record to record each index
// such that whether they are valid, if valid, record[i] = 1.
// After iterating over s, "record" will record whether index i is valid. Then find the longest
// valid string in "record".

class Solution {
public:    
    int longestValidParentheses(string s) {
        stack<int> st;
        int n = s.length();
        vector<int> record(n, 0);
        for(int i=0; i<n; i++){
            if(s[i] == ')'){
                if(!st.empty() && s[st.top()] == '('){
                    record[i] = 1;
                    record[st.top()] = 1;
                    st.pop();
                }
            }
            else{
                st.push(i);
            }        
        }
        int m = 0;
        int count = 0;
        for(int i=0; i<n; i++){
            if(record[i] == 1){
                count++;
            }
            else{
                m = max(m, count);
                count = 0;
            }
        }
        return max(m, count);
    }
};