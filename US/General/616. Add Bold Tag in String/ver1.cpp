#include <bits/stdc++.h>
using namespace std;

struct Trie{
    char c;
    unordered_map<char, Trie*> sons;
    bool ending;

    Trie(char c): c(c), ending(false) {}
};

class Solution {
public:
    void buildTrie(Trie* node, const string& word, int pos){
        if(pos == word.length()){
            node->ending = true;
            return;
        }
        if(node->sons.find(word[pos]) == node->sons.end()){
            node->sons[word[pos]] = new Trie(word[pos]);
        }
        buildTrie(node->sons[word[pos]], word, pos+1);
    }

    int search(Trie* node, const string& word, int pos){
        int ans = -1;
        if(node->ending){  // record the pos and continue searching
            ans = pos;
        }
        if(pos == word.length()){
            return ans;
        }
        if(node->sons.find(word[pos]) != node->sons.end()){
            return max(ans, search(node->sons[word[pos]], word, pos+1));
        }
        return ans;
    }

    bool needMerging(const pair<int, int>& p1, const pair<int, int>& p2){
        return p2.first <= p1.second;

    }

    string addBoldTag(string s, vector<string>& words) {
        // Build a Trie first
        Trie* root = new Trie('\0');
        for(const auto& w: words){
            buildTrie(root, w, 0);
        }
        // first is the <b> and second is </b>
        vector<pair<int, int>> tags; 
        // build tags
        for(int i=0; i<s.length(); i++){
            int pos = search(root, s, i);
            if(pos != -1){
                tags.push_back({i, pos});
            }
        }
        if(tags.size() == 0){
            return s;
        }
        // merge overlap and consecutive
        vector<pair<int, int>> merged_tags;
        pair<int, int> cur = tags.front();
        for(int i=1; i<tags.size(); i++){
            if(needMerging(cur, tags[i])){
                cur.second = max(cur.second, tags[i].second);
            }
            else{
                merged_tags.push_back(cur);
                cur = tags[i];
            }
        }
        merged_tags.push_back(cur);
        // generate interval for every substring, pair of first mean a bold tag
        vector<pair<bool, pair<int, int>>> intervals;
        if(merged_tags[0].first > 0){
            intervals.push_back({false, {0, merged_tags[0].first}});
        }
        intervals.push_back({true, merged_tags[0]});
        for(int i=1; i<merged_tags.size(); i++){
            intervals.push_back({false, {merged_tags[i-1].second, merged_tags[i].first}});
            intervals.push_back({true, {merged_tags[i]}});
        }
        if(merged_tags.back().second < s.length()){
            intervals.push_back({false, {merged_tags.back().second, s.length()}});
        }
        // generate ans string
        string ans;
        for(const auto& interval: intervals){
            if(interval.first){
                ans += "<b>";
                ans += s.substr(interval.second.first, interval.second.second-interval.second.first);
                ans += "</b>";
            }
            else{
                ans += s.substr(interval.second.first, interval.second.second-interval.second.first);
            }
        }
        return ans;
    }
};