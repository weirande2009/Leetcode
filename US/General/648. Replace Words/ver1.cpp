#include <bits/stdc++.h>
using namespace std;

struct Trie{
    char c;
    bool ending;
    int no;
    unordered_map<char, Trie*> sons;

    Trie(char c): c(c), ending(false) {}
};

class Solution {
public:
    void buildTrie(Trie* node, const string& s, int pos, int no){
        if(node->sons.find(s[pos]) == node->sons.end()){
            node->sons[s[pos]] = new Trie(s[pos]);
        }
        if(s.length() == pos+1){
            node->sons[s[pos]]->ending = true;
            node->sons[s[pos]]->no = no;
        }
        else{
            buildTrie(node->sons[s[pos]], s, pos+1, no);
        }
    }

    void searchTrie(Trie* node, const string& s, int pos, int& ans){
        if(node->ending){
            ans = node->no;
            return;
        }
        if(pos == s.length()-1){
            return;
        }
        if(node->sons.find(s[pos]) == node->sons.end()){
            return;
        }
        searchTrie(node->sons[s[pos]], s, pos+1, ans);
    }

    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie* root = new Trie(0);
        for(int i=0; i<dictionary.size(); i++){
            buildTrie(root, dictionary[i], 0, i);
        }
        int cur = 0;
        string ans;
        for(int i=0; i<sentence.length(); i++){
            int p = sentence.find(" ", cur);
            int no = -1;
            string tmp_s;
            if(p == sentence.npos){
                tmp_s = sentence.substr(cur);
            }
            else{
                tmp_s = sentence.substr(cur, p-cur);
            }
            searchTrie(root, tmp_s, 0, no);
            if(no != -1){
                ans += dictionary[no];
            }
            else{
                ans += tmp_s;
            }
            
            if(p == sentence.npos){
                cur = sentence.length();
            }
            else{
                cur = p + 1;
                ans += " ";
            }
        }
        return ans;
    }
};