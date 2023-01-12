#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<string> tmp = strings;
        vector<vector<string>> results;
        int n = tmp.size();
        // try to convert all string to the same
        for(int i=0; i<n; i++){
            // convert first to 'z' and then follows
            int dis = 'z'-tmp[i][0];
            for(char& c: tmp[i]){
                c = 'a'+(c-'a' + dis)%26;
            }
        }
        unordered_map<string, vector<int>> hashtable;
        for(int i=0; i<n; i++){
            hashtable[tmp[i]].push_back(i);
        }
        for(auto& p: hashtable){
            vector<string> result;
            for(int i: p.second){
                result.push_back(strings[i]);
            }
            results.push_back(result);
        }
        return results;
    }
};