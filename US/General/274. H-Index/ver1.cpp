#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        unordered_map<int, int> hashtable;
        for(int num: citations){
            hashtable[num]++;
        }
        vector<vector<int>> record;
        for(auto& p: hashtable){
            record.push_back({p.first, p.second});
        }
        sort(record.begin(), record.end(), [](const vector<int>& v1, const vector<int>& v2){
            return v1[0] > v2[0];
        });
        vector<int> cumsum;
        cumsum.push_back(record[0][1]);
        for(int i=1; i<record.size(); i++){
            cumsum.push_back(record[i][1]+cumsum[i-1]);
        }
        int m = 0;
        for(int i=0; i<record.size(); i++){
            m = max(m, min(cumsum[i], record[i][0]));
        }
        return m;
    }
};
