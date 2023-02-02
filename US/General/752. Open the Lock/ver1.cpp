#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deadend_h;
        for(auto& s: deadends){
            deadend_h.insert(s);
        }
        if(deadend_h.find("0000") != deadend_h.end()){
            return -1;
        }
        if(target == "0000"){
            return 0;
        }
        unordered_set<string> hashtable;
        queue<string> q;
        q.push("0000");
        int steps = 0;
        while(!q.empty()){
            steps++;
            queue<string> tmp_q;
            while(!q.empty()){
                string& s = q.front();
                for(int i=0; i<4; i++){
                    int tmp = s[i];
                    // minus 1
                    s[i] = (s[i]-'0'-1+10)%10+'0';
                    if(s == target){
                        return steps;
                    }
                    if(deadend_h.find(s) == deadend_h.end() && hashtable.find(s) == hashtable.end()){
                        tmp_q.push(s);
                        hashtable.insert(s);
                    }
                    s[i] = tmp;

                    // plus 1
                    s[i] = (s[i]-'0'+1)%10+'0';
                    if(s == target){
                        return steps;
                    }
                    if(deadend_h.find(s) == deadend_h.end() && hashtable.find(s) == hashtable.end()){
                        tmp_q.push(s);
                        hashtable.insert(s);
                    }
                    s[i] = tmp;
                }
                q.pop();
            }
            q = tmp_q;
        }
        return -1;
    }
};