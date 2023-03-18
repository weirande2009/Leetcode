#include <bits/stdc++.h>
using namespace std;

class BrowserHistory {
private:
    vector<string> history;
    int mx;
    int pos;

public:
    BrowserHistory(string homepage) {
        history.push_back(homepage);
        pos = 0;
        mx = 0;
    }
    
    void visit(string url) {
        if(history.size() == pos+1){
            history.push_back("");
        }
        history[++pos] = url;
        mx = pos;
    }
    
    string back(int steps) {
        pos -= min(steps, pos);
        return history[pos];
    }
    
    string forward(int steps) {
        pos = min(pos+steps, mx);
        return history[pos];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */