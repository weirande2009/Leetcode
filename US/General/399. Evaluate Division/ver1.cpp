#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    double dfs(unordered_map<string, unordered_map<string, double>>& hashtable, unordered_set<string>& route, const string& s1, const string& s2){
        double ans = -1.0;
        if(hashtable.find(s1) != hashtable.end()){
            if(hashtable[s1].find(s2) != hashtable[s1].end()){
                return hashtable[s1][s2];
            }
            else{
                for(auto& p: hashtable[s1]){
                    if(route.find(p.first) != route.end()){
                        continue;
                    }
                    route.insert(p.first);
                    double a = dfs(hashtable, route, p.first, s2);
                    route.erase(p.first);
                    if(abs(a + 1.0) > 1e-6){
                        ans = p.second * a;
                        break;
                    }
                }
            }
        }
        return ans;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> hashtable;
        unordered_set<string> appeared_string;
        for(int i=0; i<equations.size(); i++){
            hashtable[equations[i][0]][equations[i][1]] = values[i];
            hashtable[equations[i][1]][equations[i][0]] = 1 / values[i];
            appeared_string.insert(equations[i][0]);
            appeared_string.insert(equations[i][1]);
        }
        vector<double> ans;
        for(auto& query: queries){
            if(appeared_string.find(query[0]) == appeared_string.end() || appeared_string.find(query[1]) == appeared_string.end()){
                ans.push_back(-1);
                continue;
            }
            if(query[0] == query[1]){
                ans.push_back(1);
                continue;
            }
            unordered_set<string> route;
            route.insert(query[0]);
            double a = dfs(hashtable, route, query[0], query[1]);
            ans.push_back(a);
        }
        return ans;
    }
};