#include <bits/stdc++.h>
using namespace std;

// This is the HtmlParser's API interface.
// You should not implement it, or speculate about its implementation
class HtmlParser {
  public:
    vector<string> getUrls(string url);
};


class Solution {
public:
    string get_hostname(const string& url){
        int pos = url.find("/");
        int begin_pos = pos+2;
        int end_pos = url.find("/", begin_pos);
        return url.substr(begin_pos, end_pos-begin_pos);
    }

    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        unordered_set<string> ans;
        ans.insert(startUrl);
        queue<string> q;
        q.push(startUrl);
        string hostname = get_hostname(startUrl);
        while(!q.empty()){
            string url = q.front();
            q.pop();
            vector<string> urls = htmlParser.getUrls(url);
            for(const string& s: urls){
                if(ans.find(s) == ans.end() && hostname == get_hostname(s)){
                    ans.insert(s);
                    q.push(s);
                }
            }
        }
        return vector<string>(ans.begin(), ans.end());
    }
};