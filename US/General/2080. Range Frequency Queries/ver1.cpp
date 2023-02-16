#include <bits/stdc++.h>
using namespace std;

class RangeFreqQuery {
private:
    unordered_map<int, vector<int>> hashtable;

public:
    RangeFreqQuery(vector<int>& arr) {
        int n = arr.size();
        for(int i=0; i<n; i++){
            hashtable[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int value) {
        auto lower_it = lower_bound(hashtable[value].begin(), hashtable[value].end(), left);
        auto upper_it = lower_bound(hashtable[value].begin(), hashtable[value].end(), right+1);
        return upper_it-lower_it;
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */