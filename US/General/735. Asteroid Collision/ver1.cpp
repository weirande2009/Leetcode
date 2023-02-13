#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> left;
        stack<int> s;
        for(int ast: asteroids){
            if(!s.empty() && ast < 0){
                while(!s.empty() && s.top() < -ast){
                    s.pop();
                }
            }
            if(s.empty() && ast < 0){
                left.push_back(ast);
            }
            if(!s.empty() && s.top() == -ast){
                s.pop();
            }
            if(ast > 0){
                s.push(ast);
            }
        }
        vector<int> ans(s.size());
        int i=0;
        while(!s.empty()){
            ans[ans.size()-i-1] = s.top();
            i++;
            s.pop();
        }
        ans.insert(ans.begin(), left.begin(), left.end());
        return ans;
    }
};