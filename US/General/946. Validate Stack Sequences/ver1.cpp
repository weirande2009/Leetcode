#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int i = 0;
        int j = 0;
        while(i < pushed.size() && j < popped.size()){
            // push
            s.push(pushed[i++]);
            // check pop
            while(!s.empty() && popped[j] == s.top()){
                s.pop();
                j++;
            }
        }
        return i == j;
    }
};