#include <stack>
#include <vector>
using namespace std;

// Algorithm: Only store index in stack

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // only store the index
        stack<int> s;
        int n = temperatures.size();
        vector<int> result(n, 0);
        s.push(n-1);
        for(int i=n-2; i>=0; i--){
            while(!s.empty()){
                if(temperatures[s.top()] > temperatures[i]){
                    result[i] = s.top() - i;
                    s.push(i);
                    break;
                }
                s.pop();
            }
            if(s.empty()){
                result[i] = 0;
                s.push(i);
            }
        }
        return result;
    }
};