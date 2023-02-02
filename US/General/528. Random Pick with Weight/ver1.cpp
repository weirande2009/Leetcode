#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int sum;
    vector<int> cumsum;

public:
    Solution(vector<int>& w) {
        sum = 0;
        for(int weight: w){
            sum += weight;
            cumsum.push_back(sum);
        }
    }
    
    int pickIndex() {
        int target = rand() % sum;
        auto it = upper_bound(cumsum.begin(), cumsum.end(), target);
        return it-cumsum.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */