#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;


class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, vector<unordered_set<string>>> hashtable;
        int n = accounts.size();
        for(int i=0; i<n; i++){
            int m = accounts[i].size();
            if(hashtable.find(accounts[i][0]) == hashtable.end()){
                hashtable[accounts[i][0]] = vector<unordered_set<string>>();
            }
            vector<int> record;
            for(int j=0; j<hashtable[accounts[i][0]].size(); j++){
                // find in common
                bool found = false;
                for(int k=1; k<m; k++){
                    if(hashtable[accounts[i][0]][j].find(accounts[i][k]) != hashtable[accounts[i][0]][j].end()){
                        found = true;
                        break;
                    }
                }
                if(found){
                    record.push_back(j);
                }
            }
            if(record.size() == 0){
                unordered_set<string> hashset;
                for(int k=1; k<m; k++){
                    hashset.insert(accounts[i][k]);
                }
                hashtable[accounts[i][0]].push_back(hashset);
            }
            else{
                for(int k=1; k<m; k++){
                    hashtable[accounts[i][0]][record[0]].insert(accounts[i][k]);
                }
                for(int k=1; k<record.size(); k++){
                    hashtable[accounts[i][0]][record[0]].insert(hashtable[accounts[i][0]][record[k]].begin(), hashtable[accounts[i][0]][record[k]].end());
                }
                for(int k=1; k<record.size(); k++){
                    hashtable[accounts[i][0]].erase(hashtable[accounts[i][0]].begin()+record[k]-k+1);
                }
            }
            
        }
        vector<vector<string>> result;
        for(auto& a: hashtable){
            for(auto& b: a.second){
                vector<string> r;
                for(auto& s: b){
                    r.push_back(s);
                }
                sort(r.begin(), r.end());
                r.insert(r.begin(), a.first);
                result.push_back(r);
            }
        }
        return result;
    }
};