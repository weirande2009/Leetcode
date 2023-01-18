#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    int earliestAcq(vector<vector<int>>& logs, int n) {
        sort(logs.begin(), logs.end(), [](const vector<int>& v1, const vector<int>& v2){
            return v1[0] < v2[0];
        });
        vector<unordered_set<int>> hashtable;
        int time = -1;
        for(auto& v: logs){
            vector<int> groups;
            for(int i=0; i<hashtable.size(); i++){
                if(hashtable[i].find(v[1]) != hashtable[i].end() || hashtable[i].find(v[2]) != hashtable[i].end()){
                    groups.push_back(i);
                }
            }
            if(groups.size() == 0){
                hashtable.push_back(unordered_set<int>());
                hashtable[hashtable.size()-1].insert(v[1]);
                hashtable[hashtable.size()-1].insert(v[2]);
            }
            else{
                for(int i=1; i<groups.size(); i++){
                    for(int j: hashtable[groups[i]]){
                        hashtable[groups[0]].insert(j);
                    }
                }
                for(int i=1; i<groups.size(); i++){
                    hashtable.erase(hashtable.begin()+groups[i]-i+1);
                }
                hashtable[groups[0]].insert(v[1]);
                hashtable[groups[0]].insert(v[2]);
            }
            if(hashtable.size() == 1 && hashtable[0].size() == n){
                time = v[0];
                break;
            }
        }
        return time;
    }
};