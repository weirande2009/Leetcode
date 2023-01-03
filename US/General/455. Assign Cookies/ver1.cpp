#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end(), std::greater<int>());
        sort(s.begin(), s.end(), std::greater<int>());
        int count = 0;
        int i = 0;
        for(int j=0; j<g.size() && i<s.size(); j++){
            if(g[j] <= s[i]){
                count++;
                i++;
            }
        }
        return count;
    }
};