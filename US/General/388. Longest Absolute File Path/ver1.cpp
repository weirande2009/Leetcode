#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthLongestPath(string input) {
        int i = 0;
        stack<pair<int, int>> s;
        int current_length = 0;
        int ans = 0;
        while(i < input.length()){
            int pos_n = input.find("\n", i);
            if(pos_n == input.npos){
                pos_n = input.length();
            }
            int pos_dot = input.find(".", i);
            int pos_first = i;
            while(input[pos_first] == '\t'){
                pos_first++;
            }
            int layer = pos_first - i;
            while(!s.empty() && s.top().first >= layer){
                current_length -= s.top().second;
                s.pop();
            }
            if(pos_dot > pos_n || pos_dot == input.npos){  // directory
                s.push({layer, pos_n - pos_first + 1});
                current_length += pos_n - pos_first + 1;
            }
            else{  // file
                ans = max(ans, current_length + pos_n - pos_first);
            }
            i = pos_n + 1;
        }
        return ans;
    }
};