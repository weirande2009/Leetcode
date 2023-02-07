#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> readLog(const string& log){
        int pos = log.find(":");
        int function_id = stoi(log.substr(0, pos));
        int pos1 = log.find(":", pos+1);
        int type;
        if(log.substr(pos+1, pos1-pos-1) == "start"){
            type = 0;
        }
        else{
            type = 1;
        }
        int time = stoi(log.substr(pos1+1));
        return {function_id, type, time};
    }

    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans(n, 0);
        stack<pair<int, int>> s;
        int last_time = 0;
        int last_type = 0;
        for(string& log: logs){
            vector<int> info = readLog(log);
            if(info[1] == 0){
                if(!s.empty()){
                    ans[s.top().first] += info[2] - last_time;
                    if(last_type == 1){
                        ans[s.top().first]--;
                    }
                }
                s.push({info[0], info[2]});
            }
            else{
                ans[s.top().first] += info[2] - last_time;
                if(last_type == 0){
                    ans[s.top().first]++;
                }
                s.pop();
            }
            last_time = info[2];
            last_type = info[1];
        }
        return ans;
    }
};