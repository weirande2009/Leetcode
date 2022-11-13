#include <stack>
#include <vector>
using namespace std;

// Algorithm: Use stack from back to front to record the closest smaller one. higher bigger
// should block lower smaller because it's useless.

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<vector<int>> s;
        int n = temperatures.size();
        vector<int> result(n, 0);
        s.push({temperatures[n-1], n-1});
        for(int i=n-2; i>=0; i--){
            while(!s.empty()){
                if(s.top()[0] > temperatures[i]){
                    result[i] = s.top()[1] - i;
                    s.push({temperatures[i], i});
                    break;
                }
                s.pop();
            }
            if(s.empty()){
                result[i] = 0;
                s.push({temperatures[i], i});
            }
        }
        return result;
    }
};